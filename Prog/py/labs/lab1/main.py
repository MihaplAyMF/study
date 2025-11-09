import zlib
import random
import math
from datetime import datetime
import student_utils
import student

def main():
    # 1. Контрольна сума import studentCRC32 від ПІБ + група + варіант
    data_str = f"{student.PIB}{student.GROUP}{student.VARIANT}"
    checksum = zlib.crc32(data_str.encode())
    print("1. Контрольна сума CRC32:")
    print(f"   Рядок: {data_str}")
    print(f"   Десяткове значення: {checksum}")
    print(f"   Шістнадцяткове значення: {checksum:08X}\n")

    # 2. Генерація трьох випадкових чисел і середнє арифметичне
    nums = [random.randint(1, 100) for _ in range(3)]
    avg = sum(nums) / len(nums)
    print(f"2. Випадкові числа: {nums}")
    print(f"   Середнє арифметичне: {avg:.2f}\n")

    # 3. Імпорт змінної з student_utils.py
    print(f"3. Дані студента: {student_utils.STUDENT_INFO}\n")

    # 4. Форматування рядка (f-string)
    text = (
        f"Я {student.PIB}, студент групи {student.GROUP}, "
        f"мій варіант {student.VARIANT}, вивчаю Кібербезпеку."
    )
    print(f"4. Форматований рядок:\n   {text}\n")

    # 5. Використання math — sin, cos, sqrt
    group_num = int(student.GROUP[-2:])  # останні дві цифри групи
    print(f"5. Обчислення для числа {group_num}:")
    print(f"   sin({group_num}) = {math.sin(group_num):.4f}")
    print(f"   cos({group_num}) = {math.cos(group_num):.4f}")
    print(f"   sqrt({group_num}) = {math.sqrt(group_num):.4f}\n")

    # 6. Залишок від ділення (варіант + 123) / останні дві цифри групи
    remainder = (student.VARIANT + 123) % group_num

    print(
        f"6. Залишок від ділення (варіант + 123) % "
        f"останні дві цифри групи = {remainder}\n"
    )

    # 7. Контрольна сума для рядка з 5 символів
    sample_text = "abcde"
    checksum5 = zlib.crc32(sample_text.encode()) # str in to bytes
    print(f"7. Рядок: {sample_text}")
    print(f"   CRC32 = {checksum5} (0x{checksum5:08X})\n")

    # 8. Поточна дата та час
    now = datetime.now()
    print(f"8. Поточна дата та час: {now.strftime('%Y-%m-%d %H:%M:%S')}")


if __name__ == "__main__":
    main()
