#include <iostream>

using namespace std;

double LightToAstronomica(double light);

int main()
{
    double lightYears, ansroinomicalUnitss;

    cout << "Enter the number of light yerar: ";
    cin >> lightYears;

    ansroinomicalUnitss = LightToAstronomica(lightYears);

    cout << lightYears << " light years = " << ansroinomicalUnitss << " astronomical units." << endl;

    return 0;
}

double LightToAstronomica(double light)
{
    return light * 63240;
};