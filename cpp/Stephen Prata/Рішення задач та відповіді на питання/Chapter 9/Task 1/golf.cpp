#include <iostream>
#include "golf.h"

#pragma warning(disable : 4996)


void setgolf(golf& g, const char* name, int hc)
{
	strncpy(g.fullname, name, Len - 1);
	g.fullname[Len - 1] = '\0';
	g.handicap = hc;
}

int setgolf(golf& g)
{
	char name[Len];

	std::cout << "Enter a neme: ";
	std::cin.getline(name, 40);
	std::cout << std::endl;

	if (name[0] != '\0')
	{
		strncpy(g.fullname, name, Len - 1);
	
		return 1;
	} else {
		return 0;
	}
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << "Fullname: " << g.fullname << std::endl
		<< "handicap: " << g.handicap <<std::endl;
}