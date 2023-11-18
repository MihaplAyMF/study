#include <iostream>
#include "tv.h"

using namespace std;

int main()
{
    Tv tv;
    Remote grey;

    cout << "Initial settings for TV:";
    tv.Settings();
    tv.OnOff();
    tv.ChanUp();
    tv.ChangeControlMode(grey);

    grey.SetChan(tv, 10);
    grey.VolUp(tv);
    grey.VolUp(tv);
    cout << "settings after using remote:\n";
    tv.Settings();
    grey.ShowContrloMode();


    return 0;
}