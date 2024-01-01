#include <iostream>

using namespace std;

int main()
{
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = rows; j > i; j--)
        {
            cout << ".";
        }

        for (size_t j = 0; j < i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
