#include <iostream>

using namespace std;

double HarmonicMean(double num1, double num2);

int main()
{
    setlocale(LC_ALL, "");

    double num1, num2, harmonic;

    cout << "Введіть пару чисел: ";

    while (true)
    {
        while (!(cin >> num1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Числа а не текс!! Спробуйте ще раз: ";
        }

        while (!(cin >> num2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Числа а не текс!! Спробуйте ще раз: ";
        }
        
        harmonic = HarmonicMean(num1, num2);
        cout << "Середнє гармонічне: " << harmonic;

        if (harmonic == 0)
            break; 

        cout << "\nВведіть пару чисел знову: ";
    }

    return 0;
}

inline double HarmonicMean(double num1, double num2)
{
    return (2 * num1 * num2) / (num1 + num2);

}