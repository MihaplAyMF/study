import hashlib
from datetime import datetime, timedelta
import re

# ==========================
#  КЛАС Session (Завдання 4)
# ==========================

class Session:
    def __init__(self, ip: str):
        self.ip = ip
        self.login_time = datetime.now()
        self.last_activity = self.login_time

    def is_active(self, timeout_sec: int) -> bool:
        return datetime.now() - self.last_activity < timedelta(seconds=timeout_sec)

    def touch(self) -> None:
        self.last_activity = datetime.now()

    def __str__(self):
        return (f"Session(ip={self.ip}, "
                f"login_time={self.login_time}, "
                f"last_activity={self.last_activity})")


# ==========================
#   КЛАС User (Завдання 1–4)
# ==========================

class User:

    def __init__(self, username: str, email: str, role: str,
                 active: bool, session: Session = None):
        self.username = username
        self._email = None
        self.email = email
        self.role = role
        self.active = active
        self.session = session
        self.__password_hash = None

    # ------------ Робота з паролем ------------
    def set_password(self, password: str) -> None:
        self.__password_hash = hashlib.sha256(password.encode('utf-8')).hexdigest()

    def check_password(self, password: str) -> bool:
        if self.__password_hash is None:
            return False
        return hashlib.sha256(password.encode('utf-8')).hexdigest() == self.__password_hash

    # ------------ Деактивація ------------
    def deactivate(self) -> None:
        self.active = False

    # ------------ Email property (ручна валідація) ------------
    @property
    def email(self) -> str:
        return self._email

    @email.setter
    def email(self, value: str) -> None:
        # email має містити @
        if '@' not in value:
            raise ValueError("Invalid email: missing '@'")

        name, domain = value.split('@', 1)

        # --- Перевірка name (частина до @) ---
        if not (3 <= len(name) <= 64):
            raise ValueError("Invalid email: name must be 3-64 characters")

        if not name[0].isalpha():
            raise ValueError("Invalid email: name must start with a letter")

        for ch in name:
            if not (ch.isalnum() or ch == '_'):
                raise ValueError("Invalid email: name contains invalid characters")

        # --- Перевірка домену ---
        if '.' not in domain:
            raise ValueError("Invalid email: domain must contain '.'")

        if any(part == "" for part in domain.split('.')):
            raise ValueError("Invalid email: empty domain part")

        self._email = value

    # ------------ Строкове представлення ------------
    def __str__(self) -> str:
        return (f"User(username='{self.username}', email='{self.email}', "
                f"role='{self.role}', active={self.active}, "
                f"session={self.session})")


# ==================================
#   КЛАС Admin (Завдання 3 – підклас)
# ==================================

class Admin(User):

    def __init__(self, username: str, email: str, active: bool,
                 session: Session = None):
        super().__init__(username, email, role="admin",
                         active=active, session=session)
        self.permissions = set()

    def grant_permission(self, permission: str) -> None:
        self.permissions.add(permission)

    def revoke_permission(self, permission: str) -> None:
        self.permissions.discard(permission)

    def has_permission(self, permission: str) -> bool:
        return permission in self.permissions

    def __str__(self) -> str:
        return (f"Admin(username='{self.username}', email='{self.email}', "
                f"active={self.active}, permissions={list(self.permissions)}, "
                f"session={self.session})")

# ==========================================
#   КЛАС HtmlSanitizer (Завдання 5)
# ==========================================

class HtmlSanitizer:
    
    def __init__(self, use_bleach: bool = True):
        self.use_bleach = use_bleach
        try:
            import bleach  # типу встановлена бібліотека
            self._bleach = bleach
        except ImportError:
            self._bleach = None
            self.use_bleach = False  # якщо немає bleach — переходимо на простий режим

    def sanitize_with_bleach(self, html: str) -> str:
        if not self._bleach:
            raise RuntimeError("bleach library is not available")
        # можна обмежити дозволені теги, але для прикладу залишимо стандарт
        return self._bleach.clean(html)

    def sanitize_simple(self, html: str) -> str:
        pattern = re.compile(r'<script.*?>.*?</script>', flags=re.IGNORECASE | re.DOTALL)
        cleaned = re.sub(pattern, '', html)
        return cleaned

    def sanitize(self, html: str) -> str:
        if self.use_bleach and self._bleach is not None:
            return self.sanitize_with_bleach(html)
        return self.sanitize_simple(html)


# ==========================================
#   КЛАС AuditLog (Завдання 8)
# ==========================================

class AuditLog:
    def __init__(self):
        # список записів (time, username, action)
        self.logs = []

    def add_log(self, username: str, action: str) -> None:
        self.logs.append((datetime.now(), username, action))

    def show_all(self) -> None:
        for time_val, username, action in self.logs:
            print(f"[{time_val}] {username}: {action}")


# ==========================================
#   КЛАС UserAccount (Завдання 6, 7, 8)
# ==========================================

class UserAccount:
    def __init__(self, user: User):
        self.user = user

        # Якщо у користувача ще немає сесії — створюємо
        if self.user.session is None:
            self.user.session = Session(ip="0.0.0.0")

        self.session = self.user.session
        self.sanitizer = HtmlSanitizer()
        self.audit_log = AuditLog()
        self.comments_history = []  # збережені очищені коментарі

    # ---- Доступ через [] (Завдання 7) ----
    def __getitem__(self, key: str):
        if hasattr(self, key):
            return getattr(self, key)
        raise KeyError(f"No such attribute: {key}")

    def __setitem__(self, key: str, value):
        if hasattr(self, key):
            setattr(self, key, value)
        else:
            raise KeyError(f"No such attribute: {key}")

    # ---- Методи login та post_comment (Завдання 6) ----
    def login(self, username: str, password: str, ip: str) -> bool:
        # оновлюємо сесію
        self.session.ip = ip
        self.session.touch()

        ok = (self.user.username == username and self.user.check_password(password))

        if ok:
            action = f"login success from {ip}"
        else:
            action = f"login failed from {ip}"

        self.audit_log.add_log(self.user.username, action)

        return ok

    def post_comment(self, html_text: str) -> str:
        self.session.touch()
        cleaned = self.sanitizer.sanitize(html_text)
        self.comments_history.append(cleaned)
        self.audit_log.add_log(self.user.username, "post_comment")
        return cleaned


# ==========================================
#   ДЕМОНСТРАЦІЯ (Завдання 9)
# ==========================================

if __name__ == "__main__":
    # Створюємо користувача і сесію
    session = Session("127.0.0.1")
    user = User("misha", "misha_dev@example.com", "user", True, session)
    user.set_password("mypassword")

    # Створюємо UserAccount
    account = UserAccount(user)

    # Логін (успішний)
    success = account.login("misha", "mypassword", "192.168.1.10")
    print("Login success:", success)

    # Логін (невдалий)
    failed = account.login("misha", "wrongpass", "192.168.1.11")
    print("Login success with wrong pass:", failed)

    # Публікація коментаря з HTML і <script>
    raw_comment = "<b>Привіт!</b> <script>alert('XSS');</script> Це коментар."
    clean_comment = account.post_comment(raw_comment)
    print("Очищений коментар:", clean_comment)

    # Перевірка доступу через [] (Завдання 7)
    print("Доступ до user через []:", account["user"])
    account["user"].deactivate()
    print("Після deactivate:", account["user"])

    # Показати всі логи (Завдання 8)
    print("\n=== Audit log ===")
    account.audit_log.show_all()
