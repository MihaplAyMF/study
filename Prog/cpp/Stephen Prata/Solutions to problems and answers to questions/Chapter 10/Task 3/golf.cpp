#include <iostream>
#include <string>

#include "golf.h"

Golf::Golf() {}

Golf::Golf(const char* name)
{
	strncpy(fullname, name, Len - 1);
}

int Golf::SetGolf()
{
	char name[Len];

	std::cout << "Enter a neme: ";
	std::cin.getline(name, 40);
	std::cout << std::endl;

	if (name[0] != '\0')
	{
		strncpy(fullname, name, Len - 1);

		return 1;
	} else
	{
		return 0;
	}
}

void Golf::SetGolf(const char* name)
{
	strcpy(fullname, name);
}

void Golf::SetGolf(const char* name, int hc)
{
	strcpy(fullname, name);
	handicap = hc;
}



void Golf::SetHandicap(int hc)
{
	handicap = hc;
}

void Golf::ShowGolf() const
{
	std::cout << "Fullname: " << fullname << std::endl
		<< "handicap: " << handicap << std::endl;
}