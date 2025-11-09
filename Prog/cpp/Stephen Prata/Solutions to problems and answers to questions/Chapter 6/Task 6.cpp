#include <iostream>
#include <string>

using namespace std;

struct influentialPersons
{
	string name;
	double donation;
};

int main()
{
	int SIZE;
	cout << "Enter the number of patrons: ";

	while (!(cin >> SIZE).get())
	{
		cin.clear(); cin.ignore();
		cout << "Only numbers allowed! Enter again: ";
	}

	influentialPersons* societyProtection = new influentialPersons[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "\nEnter name #" << i + 1 << ": ";
		getline(cin, societyProtection[i].name);
		cout << "Enter the donation amount: ";
	
		while (!(cin >> societyProtection[i].donation).get())
		{
			cin.clear(); cin.ignore();
			cout << "Only numbers allowed! Enter again: ";
		}

	}

	bool state = false;
	cout << "\nGrand Patrons: " << endl;

    for (size_t i = 0; i < SIZE; i++)
	{
		if (societyProtection[i].donation > 10000)
		{
			cout << societyProtection[i].name << endl;
			state = true;
		}
		else if (i + 1 == SIZE && state == false)
			cout << "none" << endl;
	}

	state = false;
	cout << "\nPatrons: " << endl;

	for (size_t i = 0; i < SIZE; i++)
	{
		if (societyProtection[i].donation < 10000)
		{
			cout << societyProtection[i].name << endl;
			state = true;
		}
		else if (i + 1 == SIZE && state == false)
			cout << "none" << endl;
	}

	delete[] societyProtection;

	return 0;
}
