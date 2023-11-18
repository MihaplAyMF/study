
#include <iostream>
#include <Windows.h> // Для коретного вводу/виводу функцій і не тільки

using namespace std;

void PrintTime(int hour, int minut);

int main()
{

    SetConsoleOutputCP(1251); // Це для коректного виводу кирилиці
    SetConsoleCP(1251); // А це для коректного вводу кирилиці

    int hours, minutes;

    cout << "Введіть число теперішньої години -> ";
    cin >> hours;
    cout << "Введіть число теперішньої хвилини -> ";
    cin >> minutes;

    PrintTime(hours, minutes);
    
    return 0;
}

void PrintTime(int hour, int minut)
{
    cout << "Час: " << hour << ":" << minut << endl;
}