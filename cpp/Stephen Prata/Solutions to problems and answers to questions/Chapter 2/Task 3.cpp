#include <iostream>
#include <Windows.h> // Для коретного вводу/виводу функцій і не тільки

using namespace std;

void BlindMice();
void MiceRun();

int main()
{

    SetConsoleOutputCP(1251); // Це для коректного виводу кирилиці
    SetConsoleCP(1251); // А це для коректного вводу кирилиці

    BlindMice();
    BlindMice();
    MiceRun();
    MiceRun();

    return 0;
}


void BlindMice()
{
    cout << "Three blind mice" << endl;
}

void MiceRun()
{
    cout << "see how they run" << endl;

}
