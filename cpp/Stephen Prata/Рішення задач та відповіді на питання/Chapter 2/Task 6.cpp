
#include <iostream>
#include <Windows.h> // Для коретного вводу/виводу функцій і не тільки

using namespace std;

double LightConverAstronomy(double light);

int main()
{

    SetConsoleOutputCP(1251); // Це для коректного виводу кирилиці
    SetConsoleCP(1251); // А це для коректного вводу кирилиці

    double lightYears;

    cout << "Введіть кількість світових років по целсію -> ";
    cin >> lightYears;

    cout << lightYears << " світових років = " << LightConverAstronomy(lightYears) << " астрономічних одиниць";

    return 0;
}

double LightConverAstronomy(double light)
{
    return light * 63240;
}