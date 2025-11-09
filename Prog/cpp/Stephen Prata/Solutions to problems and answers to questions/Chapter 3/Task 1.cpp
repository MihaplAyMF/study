#include <iostream>

using namespace std;

int main()
{
    int const inchesToFoot = 12;
    int height;

    cout << "Enter your height in inches->__\b\b";

    cin >> height;

    cout << "Your height " << height / inchesToFoot << " f " << height % inchesToFoot << " d ";

    return 0;
}
