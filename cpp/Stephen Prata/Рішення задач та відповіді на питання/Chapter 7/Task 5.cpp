#include <iostream>

using namespace std;

double Factorial(double num);

int main()
{
    setlocale(LC_ALL, "");

    int num;
    cout << "Введіть число для рахування факторіалу: ";
    while (!(cin >> num))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Дозволено лише цифри! Спробуйте ще раз: ";
    }
    
    cout << "Факторіал " << num << " = " << Factorial(num) << endl;

    return 0;
}

double Factorial(double num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * Factorial(num-1);
}