#include <iostream>
#include <string>

using namespace std;

int const MonthsInYear = 12;

int main()
{
    string months [MonthsInYear]
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int bookSales[MonthsInYear], sum {};

    for (size_t i = 0; i < MonthsInYear; i++)
    {
        cout << "Enter sales in " << months[i] << ": ";
        cin >> bookSales[i];
        sum += bookSales[i];
    }

    cout << "\nSales for the year = " << sum;

    return 0;
}
