#include <iostream>
#include "file2.h"

SALES::Sales::Sales() {};
SALES::Sales::Sales(double sales[QUARTERS]) 
{
	for (int i = 0; i < QUARTERS; i++)
	{
		this->sales[i] = sales[i];
	}
};

void SALES::Sales::setSales(const double ar[], int n)
{
	double max { ar[0] }, min { ar[0] }, average {};
	for (size_t i = 0; i < n; i++)
	{
		sales[i] = ar[i];
		if (max < ar[i])
			max = ar[i];
		if (min > ar[i])
			min = ar[i];
		average += ar[i];
	}
	average = average / n;
	max = max;
	min = min;
}

void SALES::Sales::setSales()
{
	double max { sales[0] }, min { sales[0] }, average {};
	for (size_t i = 0; i < 4; i++)
	{
		if (max < sales[i])
			max = sales[i];
		if (min > sales[i])
			min = sales[i];
		average += sales[i];
	}
	average = average / 4;
	max = max;
	min = min;
}

void SALES::Sales::showSales() const
{
	std::cout << "Salse: ";
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << sales[i] << " ";
	}
	std::cout << std::endl
		<< "Average - " << average << std::endl
		<< "Max - " << max << std::endl
		<< "Min - " << min << std::endl;
}