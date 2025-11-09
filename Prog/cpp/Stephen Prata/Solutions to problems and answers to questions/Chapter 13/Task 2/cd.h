#pragma once

class Cd
{
private:
    char* perfomers;
    char* label;
    int selection;
    double playtime;
public:
    Cd() = default;
    Cd(const char* sOne, const char* sTwo, int number, double value);
    Cd(const Cd& other) = default;
    ~Cd();
    virtual void Report() const;
    Cd& operator=(const Cd& other) = default;
};
