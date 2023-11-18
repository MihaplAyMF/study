#pragma once
#include "cd.h"

class Classic : public Cd
{
private:
    char* name;
public:
    Classic() = default;
    Classic(const char* sOne, const char* sTwo, const char* sThree, int number, double value);
    ~Classic();
    void Report() const override;
};
