#include <iostream>

using namespace std;

int main()
{
    int numOne, numTwo, sum {};

    cout << "Enter first number: ";
    cin >> numOne;
    cout << "Enter second number: ";
    cin >> numTwo;

    for (int i = numOne; i < numTwo; i++)
    {
        sum += i;
    }

    cout << "Sum from " << numOne << " to " << numTwo << " = " << sum;

    return 0;
}
