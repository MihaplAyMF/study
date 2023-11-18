#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    double x, y, z;

    cout << "Enter two numbers: ";
    while(cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch(logic_error& e)
        {
            cout << e.what() << endl
                << "You lose" << endl;
            continue;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if(a == -b)
        throw logic_error("Error hmean(). Invalid arguments: a = -b");
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if(a < 0 || b < 0)
        throw logic_error("Error gmean(). Arguments should be >= 0");
    return std::sqrt(a * b);
}
