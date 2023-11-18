#include <iostream>
#include <Windows.h> // Для коретного вводу/виводу функцій і не тільки

using namespace std;

int main()
{

    SetConsoleOutputCP(1251); // Це для коректного виводу кирилиці
    SetConsoleCP(1251); // А це для коректного вводу кирилиці

    cout << "Моє ім'я Федик Михайло" << endl;
    cout << "Мій адрес Площа Ринок 1.5" << endl;

    return 0;
}


