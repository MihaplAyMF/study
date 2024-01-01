#include <iostream>
#include "Cow.h"

using namespace std;

int main() 
{
	Cow test("Miha", "Programmin, reading", 66);
	test.Show();
	Cow Two = test;
	Two.Show();
	return 0;
}	