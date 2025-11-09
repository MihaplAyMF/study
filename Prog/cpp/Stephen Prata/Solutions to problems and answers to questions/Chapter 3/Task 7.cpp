#include <iostream>

using namespace std;

void PrintTime(double minute, double hours);

int main()
{
    double minute, hours;

    cout << "Enter the numЬer of hours: ";
    cin >> hours;
    cout << "Enter the numЬer of minutes: ";
    cin >> minute;

    PrintTime(minute, hours);

    return 0;
}

void PrintTime(double minute, double hours)
{
    cout << "Time: " << hours << ":" << minute << endl;
};