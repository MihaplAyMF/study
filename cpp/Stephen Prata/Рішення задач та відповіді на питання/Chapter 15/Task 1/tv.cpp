#include <iostream>
#include "tv.h"

using std::cout;
using std::endl;

bool Tv::VolUp()
{
    if(volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::VolDown()
{
    if(volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::ChanUp()
{
    if(channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::ChanDown()
{
    if(channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::Settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if(state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV ? "TV" : "DVD") << endl;    
    }
}

void Tv::ChangeControlMode(Remote& r) const
{
    if(state == On)
        r.controlMode == Remote::Normal ? r.controlMode = Remote::Interactive : r.controlMode = Remote::Normal;
}

void Remote::ShowContrloMode() const
{
    cout << "Control mode: " << controlMode << endl;
}