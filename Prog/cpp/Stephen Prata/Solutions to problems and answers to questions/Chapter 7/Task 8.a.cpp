#include <iostream>
#include <array>
#include <string>

using namespace std;

const int Seasons = 4;
const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

void fill(double arr[]);
void show(double arr[]);

int main()
{
    double expenses[Seasons];

    fill(expenses);
    show(expenses);

    return 0;
}

void fill(double arr[])
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> arr[i];
    }
}

void show(double arr[])
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << arr[i] << '\n';
        total += arr[i];
    }
    cout << "Total: $" << total << '\n';
}
