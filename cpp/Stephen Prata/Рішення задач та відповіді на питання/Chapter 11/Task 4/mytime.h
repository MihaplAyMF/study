#pragma once
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);

    friend Time operator+(Time& t1, Time& t2);
    friend Time operator-(Time& t1, Time& t2);
    friend Time operator*(Time& t, double n);   
    friend Time operator*(double n, Time& t)
        { return t * n; } 
    
    friend std::ostream & operator<<(std::ostream & os, const Time & t);

};