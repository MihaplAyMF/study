#include <iostream>
#include "cd.h"

Cd::Cd(const char* sOne, const char* sTwo, int number, double value)
	: selection(number), playtime(value)
{
	strncpy(perfomers, sOne, 50);
	strncpy(label, sTwo, 20);
}

void Cd::Report() const
{
	std::cout << std::endl
		<< "Copact dist inforpation: " << std::endl
		<< "Perfomers: " << perfomers << std::endl
		<< "label: " << label << std::endl
		<< "selection: " << selection << std::endl
		<< "playtime: " << playtime << std::endl;
}
