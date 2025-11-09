#include <iostream>
#include <string>

using namespace std;

int const MonthsInYear = 12;
int const QuantityYear = 3;

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
    int bookSales[QuantityYear][MonthsInYear], sumYear[3]{}, sum{};

    for (size_t i = 0; i < QuantityYear; i++)
    {
        cout << "Year " << i+1 << endl;
        for (size_t j = 0; j < MonthsInYear; j++)
        {
            cout << "Enter sales in " << months[j] << ": ";
            cin >> bookSales[i][j];
            sumYear[i] += bookSales[i][j];
        } 
        cout << "\nSales for " << i+1 << " year = " << sumYear[i] << endl;
        sum += sumYear[i];
    }

    cout << "Summary sales = " << sum << endl;

    return 0;
}
