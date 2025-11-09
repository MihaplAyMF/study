# --- Завдання 2: Система контролю доступу ---

users = {
    "ai_security_expert": {
        "role": "ai_security",
        "clearance": 4,
        "department": "AI Security",
        "active": True,
    },
    "ml_engineer": {
        "role": "ml_engineer",
        "clearance": 3,
        "department": "Machine Learning",
        "active": True,
    },
    "data_engineer": {
        "role": "data_engineer",
        "clearance": 2,
        "department": "Data Engineering",
        "active": True,
    },
    "research_assistant": {
        "role": "researcher",
        "clearance": 2,
        "department": "Research",
        "active": True,
    },
    "training_bot": {
        "role": "bot_account",
        "clearance": 1,
        "department": "Automation",
        "active": False,
    },
}

resources = [
    ("ai_models", 4),
    ("training_datasets", 3),
    ("data_pipelines", 2),
    ("research_notebooks", 2),
    ("model_artifacts", 4),
    ("synthetic_data", 1),
    ("adversarial_tests", 3),
    ("model_registry", 4),
    ("feature_stores", 2),
    ("public_models", 1),
]

security_levels = (
    "Open Source",
    "Internal Research",
    "Proprietary",
    "Trade Secret",
)

blocked_users = {"training_bot", "model_theft", "data_poisoning_acc"}

# --- 1. Вивести список ресурсів ---
print("Список ресурсів системи:")
print("-" * 60)
for name, level in resources:
    level_name = security_levels[level - 1]
    print(f"{name:<25} | рівень безпеки: {level_name}")
print("-" * 60)


# --- 2. Функція перевірки доступу ---
def check_access(user_id, _resource_name, required_level):
    """Перевіряє, чи має користувач доступ до ресурсу."""
    if user_id not in users:
        return "DENY (reason: user_not_found)"

    user = users[user_id]

    if user_id in blocked_users:
        return "DENY (reason: user_blocked)"

    if not user["active"]:
        return "DENY (reason: user_inactive)"

    if user["clearance"] < required_level:
        return "DENY (reason: insufficient_clearance)"

    return "ALLOW"


# --- 3. Перевірка доступу всіх користувачів ---
print("Результати перевірки доступу:")
print("-" * 60)
for usr_name in users:
    for res_name, res_level in resources:
        result = check_access(usr_name, res_name, res_level)
        print(f"user={usr_name:<20} resource={res_name:<20} → {result}")
