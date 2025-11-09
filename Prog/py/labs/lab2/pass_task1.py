import random
import string

# --- Початкові дані ---
passwords = [
    "SIEM@An4lysis", "easy123", "S0C@Analyst",
    "observer", "Threat@Hunt1ng", "viewer",
    "Incid3nt@Handle", "monitor", "Log@An4lysis", "watcher"
]

criteria = {
    "min_length": 9,
    "require_digits": True,
    "require_upper": True,
    "require_special": True
}

forbidden_passwords = {
    "easy123", "observer", "viewer", "monitor", "watcher", "admin"
}

complexity_levels = ("Слабкий", "Середній", "Сильний", "Дуже сильний")

# --- 1. Додаємо 3 дублікати випадкових паролів ---
for _ in range(3):
    passwords.append(random.choice(passwords))

print("Всі паролі:", passwords)
print("-" * 60)


# --- Перевірка базових критеріїв ---
def fails_basic_criteria(password):
    """Перевіряє, чи пароль не відповідає базовим вимогам."""
    if len(password) < criteria["min_length"]:
        return True
    if criteria["require_digits"] and not any(c.isdigit() for c in password):
        return True
    if criteria["require_upper"] and not any(c.isupper() for c in password):
        return True
    if (
        criteria["require_special"]
        and not any(c in string.punctuation for c in password)
    ):
        return True
    if not any(c.islower() for c in password):
        return True
    return False


# --- 2. Функція для перевірки пароля ---
def evaluate_password_strength(password, all_passwords):
    """Оцінює надійність пароля та повертає його рівень."""
    # Перевірка чорного списку
    if password.lower() in forbidden_passwords:
        return complexity_levels[0]

    length = len(password)
    has_digit = any(c.isdigit() for c in password)
    has_upper = any(c.isupper() for c in password)
    has_lower = any(c.islower() for c in password)
    has_special = any(c in string.punctuation for c in password)

    # Якщо не виконується хоча б один критерій — слабкий
    if fails_basic_criteria(password):
        return complexity_levels[0]

    # Частково відповідає критеріям
    groups = sum([has_digit, has_upper, has_lower, has_special])
    if groups < 4:
        return complexity_levels[1]

    # Виконує всі вимоги
    if length < criteria["min_length"] + 4:
        return complexity_levels[2]

    # Перевірка унікальності
    if all_passwords.count(password) == 1:
        return complexity_levels[3]

    return complexity_levels[2]


# --- 3. Аналіз усіх паролів ---
results = []
for pw in passwords:
    level = evaluate_password_strength(pw, passwords)
    results.append((pw, level))

# --- 4. Виведення результатів ---
print(f"{'Пароль':<25} | {'Надійність'}")
print("-" * 45)
for pw, level in results:
    print(f"{pw:<25} | {level}")
