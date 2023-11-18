#include <iostream>
#include "classic.h"

Classic::Classic(const char* sOne = "Nothing", const char* sTwo = "Nothing", const char* sThree = "Nothing", int number = 0, double value = 0)
	: Cd(sOne, sTwo, number, value)
{
	strncpy(name, sThree, 40);
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "name: " << name << std::endl;
}

