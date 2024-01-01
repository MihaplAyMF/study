#include <iostream>

using namespace std;

int main()
{
    int num = 1, sum = 0;

    cout << "Enter 0 to finish" << endl;

    while (num != 0)
    {
        cout << "Enter a number: ";
        cin >> num;
        sum += num;
        cout << "Sum of the entere numbers = " << sum << endl;
    }

    return 0;
}
