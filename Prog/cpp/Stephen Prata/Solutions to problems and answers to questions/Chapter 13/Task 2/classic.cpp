#include <iostream>
#include "classic.h"

Classic::Classic(const char* sOne = "Nothing", const char* sTwo = "Nothing", const char* sThree = "Nothing", int number = 0, double value = 0)
	: Cd(sOne, sTwo, number, value)
{
	int size = strlen(sThree);
	name = new char[size + 1];
	strcpy(name, sOne);
	name[size] = '\n';
}

Classic::~Classic()
{
	delete[] name;
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "name: " << name << std::endl;
}

