#include <iostream>
#include <Windows.h> // Для коретного вводу/виводу функцій і не тільки

using namespace std;

int main()
{

    SetConsoleOutputCP(1251); // Це для коректного виводу кирилиці
    SetConsoleCP(1251); // А це для коректного вводу кирилиці

    int age;

    cout << "Введіть свій вік -> ";
    cin >> age;

    cout << "Ваш вік в місяцях " << age * 12;

    return 0;
}

