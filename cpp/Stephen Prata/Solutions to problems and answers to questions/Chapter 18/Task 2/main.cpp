#include <iostream> 
#include "cpmv.h"

using namespace std;

int main()
{
	Cpmv obj1 {"str1", "str2"};
	obj1.Display();
	
	Cpmv obj2 = obj1;
	obj2.Display();
	
	Cpmv obj3 = obj1 + obj2;
	obj3.Display();

	Cpmv obj4 = move(obj1);
	obj4.Display();
	obj4.Display();

	return 0;
}