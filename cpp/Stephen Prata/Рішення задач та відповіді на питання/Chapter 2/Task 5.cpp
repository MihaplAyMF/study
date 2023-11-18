
#include <iostream>
#include <Windows.h> // Для коретного вводу/виводу функцій і не тільки

using namespace std;

int main()
{

    SetConsoleOutputCP(1251); // Це для коректного виводу кирилиці
    SetConsoleCP(1251); // А це для коректного вводу кирилиці

    int celsius;

    cout << "Введіть температуру по целсію -> ";
    cin >> celsius;

    cout << "Темература по фаренгейту " << 1.8 * celsius + 32;

    return 0;
}

