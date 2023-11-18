#include <iostream>
#include "file2.h"

void SALES::setSales(Sales& s, const double ar[], int n)
{
	double max {ar[0]}, min {ar[0]}, average {};
	for (size_t i = 0; i < n; i++)
	{
		s.sales[i] = ar[i];
		if (max < ar[i])
			max = ar[i];
		if (min > ar[i])
			min = ar[i];
		average += ar[i];
	}
	s.average = average / n;
	s.max = max;
	s.min = min;
}

void SALES::setSales(Sales& s) 
{
	double max { s.sales[0] }, min { s.sales[0] }, average {};
	for (size_t i = 0; i < 4; i++)
	{
		if (max < s.sales[i])
			max = s.sales[i];
		if (min > s.sales[i])
			min = s.sales[i];
		average += s.sales[i];
	}
	s.average = average / 4;
	s.max = max;
	s.min = min;
}

void SALES::showSales(const Sales& s)
{
	std::cout << "Salse: ";
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << s.sales[i] << " ";
	}
	std::cout << std::endl 
		<< "Average - " << s.average << std::endl
		<< "Max - " << s.max << std::endl
		<< "Min - " << s.min << std::endl;
}