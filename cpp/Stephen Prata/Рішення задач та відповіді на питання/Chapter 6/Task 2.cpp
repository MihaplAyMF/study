#include <iostream>
#include <array>

using namespace std;

int main()
{
    int const SIZE = 10;
    int i = 0, moreAverageSum {};
    double sum {}, averageSum;
    array<double, SIZE> donation;

    cout << "Enter don't number to complete program" << endl << endl;

    while (!cin.fail())
    {
        if (i == 10)
        {
            cout << "to many donation" << endl;
            break;
        }
        cout << "Enter the donation amount #" << i+1 << ": ";
        cin >> donation[i];
        sum += donation[i];
        i++;
    }

    averageSum = sum / (i + 1);
    cout << "\nAverage donation amountm: " << averageSum << endl;

    for (size_t j = 0; j < i; j++)
    {
        if (donation[j] > averageSum)
            moreAverageSum++;
    }

    cout << "The number of donations is above average: " << moreAverageSum << endl;

    return 0;
}