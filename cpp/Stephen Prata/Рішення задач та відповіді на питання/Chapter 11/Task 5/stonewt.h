#pragma once
#include <iostream>

using std::ostream;
using std::cout;

class Stonewt
{
public:
    enum Mode { POUNDS, STONE };
private:
    enum {LbsPerStn = 14};      // pounds per stone
    int stone;                 // whole stones
    double pds_left;              // fractional pounds
    double pounds;  // entire weight in pounds
    Mode mode;
public:
    Stonewt(int stn, double lbs, Mode form = STONE); // construct from stone, lbs
    Stonewt(double lbs, Mode form = POUNDS); // construct from stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();

    void PoundsMode() { mode = POUNDS; }
    void StoneMode() { mode = STONE; }
    Stonewt operator+(double other);
    Stonewt operator-(double other);
    Stonewt operator*(double other);

    friend Stonewt operator+(double other, Stonewt& st);
    friend Stonewt operator-(double other, Stonewt& st);
    friend Stonewt operator*(double other, Stonewt& st);

    friend Stonewt operator+(Stonewt& st1, Stonewt& st2);
    friend Stonewt operator-(Stonewt& st1, Stonewt& st2);
    friend Stonewt operator*(Stonewt& st1, Stonewt& st2);

    friend ostream& operator<<(ostream& os, const Stonewt& v);

    explicit operator int() const;
    explicit operator double() const;
};
