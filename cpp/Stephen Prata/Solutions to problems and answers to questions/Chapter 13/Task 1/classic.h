#pragma once
#include "cd.h"

class Classic : public Cd
{
private:
    char name[40];
public:
    Classic() = default;
    Classic(const char* sOne, const char* sTwo, const char* sThree, int number, double value);

    void Report() const override;
};
