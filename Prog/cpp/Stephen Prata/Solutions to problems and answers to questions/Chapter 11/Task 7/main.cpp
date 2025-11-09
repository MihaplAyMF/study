#include <iostream>
#include "complex1.h"

using namespace std;

int main()
{
	Complex a(3.0, 4.0);
	Complex c;
	cout << "Enter а complex number(q to quit):" << endl;
	
	while(cin >> c) 
	{
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c" << a + c << endl;
		cout << "a - c" << a - c << endl;
		cout << "a * c" << a * c << endl;
		cout << "2 * c" << 2 * c << endl;
		cout << "Enter а complex number(q to quit):" << endl;
	}

	cout << "Done!" << endl;
	return 0;
}
