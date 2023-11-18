#include "stonewt.h"

//construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode form )
{
    mode = form;
    stone = stn;
    pds_left = lbs;
    pounds = stn * LbsPerStn + lbs;
}

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Mode form)
{
    mode = form;
    stone = static_cast<int>(lbs) / LbsPerStn;    // integer division
    pds_left = static_cast<int>(lbs) % LbsPerStn + lbs - static_cast<int>(lbs);
    pounds = lbs;
}


Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0.0;
}

Stonewt::~Stonewt()         // destructor
{

} 

ostream& operator<<(ostream& os, const Stonewt& v)
{
    if(v.mode == Stonewt::POUNDS)
        cout << v.pounds << " pounds\n";
    else if(v.mode == Stonewt::STONE)
    {
        cout << v.stone << " stone, " << v.pds_left << " pounds\n";
    }
    else
        os << "Stonewt object mode is invalid";
    return os;
}

Stonewt Stonewt::operator*(double other)
{
    return Stonewt(other * pounds);
}

Stonewt operator*(double other, Stonewt& st)
{
    return Stonewt(other * st.pounds);
}

Stonewt operator+(Stonewt& st1, Stonewt& st2)
{
    return Stonewt(st1.pounds + st2.pounds, st1.mode);
}

Stonewt operator*(Stonewt& st1, Stonewt& st2)
{
    return Stonewt(st1.pounds * st2.pounds, st1.mode);
}

Stonewt operator-(Stonewt& st1, Stonewt& st2)
{
    return Stonewt(st1.pounds - st2.pounds, st1.mode);
}

Stonewt Stonewt::operator-(double other)
{
    return Stonewt(other - pounds);
}

Stonewt operator-(double other, Stonewt& st)
{
    return Stonewt(other - st.pounds);
}

Stonewt Stonewt::operator+(double other)
{
    return Stonewt(other + pounds);
}

Stonewt operator+(double other, Stonewt& st)
{
    return Stonewt(other + st.pounds);
}

// conversion functions
Stonewt::operator int() const
{
    return int (pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds; 
}
