#include <iostream>
#include "file2.h"

using namespace std;

int main()
{
	SALES::Sales sl1 {{4.3, 6.2, 5.7, 8.1}};
	SALES::Sales sl2;
	
	double ar[4] = { 9.5, 4.2, 6.7, 5.1 };

	SALES::setSales(sl1);
	SALES::setSales(sl2, ar, 4);

	SALES::showSales(sl1);
	SALES::showSales(sl2);

	return 0;
}
