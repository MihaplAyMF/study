#include <iostream>

using namespace std;

int main()
{
    int degrees, minutes, seconds;
    double onlyDegrees;

    cout << "Enter а latitude in degrees, minutes, and seconds :" << endl;
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;

    onlyDegrees = degrees + minutes / 60.0 + seconds / pow(60.0, 2);

    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << onlyDegrees << " degrees";
    
    
    return 0;
}
