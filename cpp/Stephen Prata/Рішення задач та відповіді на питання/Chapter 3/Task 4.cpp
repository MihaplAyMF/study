#include <iostream>

using namespace std;

int main()
{
    const int secInDay = 24*60*60, secInHour = 60*60, secInminue = 60;
    long long seconds;
    int finalDays, finalHours, finalMunutes, finalSeconds;

    cout << "Enter the number of seconds: ";  
    cin >> seconds;

    finalDays = seconds / secInDay;
    finalSeconds = seconds % secInDay;
    finalHours = seconds / secInHour;
    finalSeconds %= secInHour;
    finalMunutes = seconds / secInminue;
    finalSeconds %= secInminue;

    cout << seconds << " secodns = " << finalDays << " days, " << finalHours << " hours, " << finalMunutes << " minute, " << finalSeconds << " seconds";
    
    return 0;
}
