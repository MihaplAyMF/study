#include <iostream>
#include "stonewt.h"

using namespace std;

int main()
{
	Stonewt arrSix[6];
	
	arrSix[0] = {180};
	arrSix[1] = {11, 8};
	arrSix[2] = {6, 12};
	
	for(size_t i = 3; i < 6; i++)
	{
		double temp;
		cout << "Pound: ";
		cin >> temp;
		arrSix[i] = temp;
		arrSix[i].StoneMode();
	}

	Stonewt stoneEleven(11, 0);
	Stonewt min(arrSix[0]), max(arrSix[0]);
	int count {};
	for(size_t i = 0; i < 6; i++)
	{
		if(arrSix[i] > max)
			max = arrSix[i];
		if(arrSix[i] < min)
			min = arrSix[i];
		if(arrSix[i] >= stoneEleven)
			count++;
	}

	cout << "Max element of array: " << max;
	cout << "Min element of array: " << min;
	cout << "Count elements than large 11 stones: " << count;
	return 0;
}
