//usetime3.cpp -- using the fourth draft of the Time class
// compile usetime3.cpp and mytime3.cpp together
#include <iostream>
#include "stonewt.h"

using namespace std;

int main()
{
	Stonewt oneObj(7, 2);
	Stonewt twoObj(80);

	cout << oneObj;
	cout << twoObj;
	cout << endl;
	cout << oneObj + twoObj;
	cout << oneObj - twoObj;
	cout << oneObj * twoObj;
	cout << endl;
	cout << oneObj + 20;
	cout << oneObj - 20;
	cout << oneObj * 20;
	cout << endl;
	cout << 20 + twoObj;
	cout << 20 - twoObj;
	cout << 20 * twoObj;
	cout << endl;
	Stonewt threeObj = oneObj + twoObj;
	threeObj.PoundsMode();
	cout << threeObj;
	threeObj.StoneMode();
	cout << threeObj;
}
