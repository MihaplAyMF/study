#include <iostream>

using namespace std;

int main()
{
	long int income;
	cin >> income;

	while (!cin.fail() && income > 0)
	{
		if (income < 5000)
			cout << "Tax is 0 twarps" << endl;
		else if (income < 15000)
			cout << "Tax is " << (income - 5000) * 0.1 << " twarps" << endl;
		else if (income < 35000)
			cout << "Tax is " << (income - 15000) * 0.15 + 1000 << " twarps" << endl;
		else 
			cout << "Tax is " << (income - 35000) * 0.2 + 4000 << " twarps" << endl;

		cout << ": ";
		cin >> income;
	}

	return 0;
}