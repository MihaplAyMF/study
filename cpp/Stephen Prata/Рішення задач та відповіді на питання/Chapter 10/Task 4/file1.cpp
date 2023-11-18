#include <iostream>
#include "file2.h"

using namespace std;

int main()
{
	double arOne[4] = { 4.3, 6.2, 5.7, 8.1 };

	SALES::Sales sl1 {arOne};
	SALES::Sales sl2;

	double ar[4] = { 9.5, 4.2, 6.7, 5.1 };

	sl1.setSales();
	sl2.setSales(ar, 4);

	sl1.showSales();
	sl2.showSales();

	return 0;
}
