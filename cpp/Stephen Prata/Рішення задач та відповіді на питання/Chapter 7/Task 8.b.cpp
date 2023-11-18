#include <iostream>
#include <array>
#include <string>

using namespace std;

const int Seasons = 4;
const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

struct Expenses
{
    double expenses[Seasons];
};

void fill(Expenses& exp);
void show(Expenses& exp);

int main()
{
    Expenses expenses;

    fill(expenses);
    show(expenses);

    return 0;
}

void fill(Expenses& exp)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> exp.expenses[i];
    }
}

void show(Expenses& exp)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << exp.expenses[i] << '\n';
        total += exp.expenses[i];
    }
    cout << "Total: $" << total << '\n';
}
