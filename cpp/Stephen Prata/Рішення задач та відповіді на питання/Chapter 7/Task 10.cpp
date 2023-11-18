#include <iostream>

using namespace std;

double Add(double numOne, double numTwo);
double Minus(double numOne, double numTwo);
double Multiplying(double numOne, double numTwo);
double Division(double numOne, double numTwo);
double Calculate(double numOne, double numTwo, double (operation)(double, double));

int main()
{
    setlocale(LC_ALL, "");

    double numOne = 5, numTwo = 10;

    double (*pf[4]) (double, double);
    pf[0] = Add;
    pf[1] = Minus;
    pf[2] = Multiplying;
    pf[3] = Division;

    int stateOperation {};

    while (true)
    {
        cout << "Введіть перше число: ";
        while (!(cin >> numOne))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Дозволено лише цифри! Спробуйте ще раз: ";
        }
        cout << "Введіть друге число: ";
        while (!(cin >> numTwo))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Дозволено лише цифри! Спробуйте ще раз: ";
        }
        cout << "Виберіть операцію: " << endl
            << "1 - Додавання" << endl
            << "2 - Віднімання" << endl
            << "3 - Множення" << endl
            << "4 - Ділення" << endl
            << "-> ";
        while (true)
        {
            if (!(cin >> stateOperation))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Лише цифри дозволені! Спробуйте ще раз: ";
                continue;
            } else if (stateOperation <= 0 || stateOperation >= 5)
            {
                cout << "Лише цифри зі списку! Спробуйте ще раз: ";
                continue;
            }
            break;
        }

        switch (stateOperation)
        {
            case 1:
                cout << "Num one + num two = " << 
                    Calculate(numOne, numTwo, pf[0]) << endl;
                break;
            case 2:
                cout << "Num one - num two = " <<
                    Calculate(numOne, numTwo, pf[1]) << endl;
                break;
            case 3:
                cout << "Num one * num two = " <<
                    Calculate(numOne, numTwo, pf[2]) << endl;
                break;
            case 4:
                cout << "Num one / num two = " <<
                    Calculate(numOne, numTwo, pf[3]) << endl;
                break;
        }
    }

    return 0;
}

double Add(double numOne, double numTwo)
{
    return numOne + numTwo;
}

double Minus(double numOne, double numTwo)
{
    return numOne - numTwo;
}

double Multiplying(double numOne, double numTwo)
{
    return numOne * numTwo;
}

double Division(double numOne, double numTwo)
{
    return numOne / numTwo;
}

double Calculate(double numOne, double numTwo, double (operation)(double, double))
{
    return operation(numOne, numTwo);
}