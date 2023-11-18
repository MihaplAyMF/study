#include <iostream>
#include "cd.h"

Cd::Cd(const char* sOne, const char* sTwo, int number, double value)
	: selection(number), playtime(value)
{
	int size = strlen(sOne);
	perfomers = new char[size + 1];
	strcpy(perfomers, sOne);
	perfomers[size] = '\0';

	size = strlen(sTwo);
	label = new char[size + 1];
	strcpy(label, sTwo);
	label[size] = '\0';
}

Cd::~Cd()
{
	delete[] perfomers;
	delete[] label;
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
