#include <iostream>

using namespace std;

double CelToFah(double celsium);

int main()
{
    double celsium, fahrenheit;

    cout << "Please enter a Celsium value: ";
    cin >> celsium;

    fahrenheit = CelToFah(celsium);

    cout << celsium << " degrees Celsium is " << fahrenheit << " degrees Fahrenheit." << endl; 

    return 0;
}

double CelToFah(double celsium)
{
    return 1.8 * celsium + 32;
}