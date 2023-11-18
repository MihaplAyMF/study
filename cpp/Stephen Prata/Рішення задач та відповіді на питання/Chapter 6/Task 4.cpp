#include <iostream>
#include <string>

using namespace std;

struct Bop
{
	string fullName;
	string title;
	string bopName;
	int preference;
};

int main()
{
	int const SIZE = 3;
	Bop bop[SIZE];
	char ch;

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Programmist #" << i + 1 << endl;
		cout << "Enter full name: ";
		getline(cin, bop[i].fullName);
		cout << "Enter title: ";
		getline(cin, bop[i].title);
		cout << "Enter bopName: ";
		getline(cin, bop[i].bopName);
		cout << "Enter preference (1, 2 or 3): ";
		(cin >> bop[i].preference).get();
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Only number!!\n: ";
			(cin >> bop[i].preference).get();
		}
		cout << endl;
	}

	cout << "Please enter one of the following choices: " << endl;
	cout << "a) display by name\tb) display by title" << endl;
	cout << "c) display by bopname\td) display by preference" << endl;
	cout << "q) quit" << endl << ": ";

	cin.get(ch).get();

	while (ch != 'q' && ch != 'Q')
	{
		switch (ch)
		{
			case 'a':
			case 'A':
				for (size_t i = 0; i < SIZE; i++)
					cout << bop[i].fullName << endl;
				break;
			case 'b':
			case 'B':
				for (size_t i = 0; i < SIZE; i++)
					cout << bop[i].title << endl;
				break;
			case 'c':
			case 'C':
				for (size_t i = 0; i < SIZE; i++)
					cout << bop[i].bopName << endl;
				break;
			case 'd':
			case 'D':
				for (size_t i = 0; i < SIZE; i++)
					cout << bop[i].preference << endl;
				break;
			default:
				cout << "Please enter а a, b, c, or d: ";
				cin.get(ch).get(); continue;
				break;
		}
		cout << ": ";
		cin.get(ch).get();
	}

	cout << "\nBye!" << endl;

	return 0;
}