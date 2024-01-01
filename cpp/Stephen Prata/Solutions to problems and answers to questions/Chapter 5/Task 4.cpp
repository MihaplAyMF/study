#include <iostream>

using namespace std;

int main()
{
    int const startBalance = 100;
    double daphne = startBalance, cleo = startBalance, i = 1;

    cout << "Year\tDaphne\tCleo" << endl;

    while (cleo <= daphne)
    {
        cout << i++ << "\t" << daphne << "\t" << cleo << endl;

        daphne += 0.1 * startBalance;
        cleo += 0.05 * cleo;

    }

    return 0;
}
