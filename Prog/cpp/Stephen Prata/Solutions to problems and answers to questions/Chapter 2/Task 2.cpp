#include <iostream>
#include <Windows.h> // Для коретного вводу/виводу функцій і не тільки

using namespace std;

int main()
{

    SetConsoleOutputCP(1251); // Це для коректного виводу кирилиці
    SetConsoleCP(1251); // А це для коректного вводу кирилиці

    int farlong;
 
    cout << "Введіть відстань в фарлонгах -> ";
    
    cin >> farlong;

    cout << endl << " " << farlong << " = " << farlong * 201168 << "м" << endl;

    return 0;
}


