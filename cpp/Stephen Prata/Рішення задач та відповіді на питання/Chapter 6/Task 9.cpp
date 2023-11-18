#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

struct influentialPersons
{
	string name;
	double donation;
};

int main()
{
	ifstream file;
	file.open("Patrons.txt");

	if (!file.is_open())
	{
		cout << "Error opening file" << endl;
		system("pause");
		return 1;
	} 
	else
	{
		cout << "file \"Patrons.txt\" open successfully" << endl << endl;
	}

	int SIZE;
	if (!(file >> SIZE).get())
	{
		cout << "the file is corrupted" << endl;
		system("pause");
		return 1;
	}

	influentialPersons* societyProtection = new influentialPersons[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		getline(file, societyProtection[i].name);
		cout << societyProtection[i].name << endl;
		if (!(file >> societyProtection[i].donation).get())
		{
			cout << "the file is corrupted" << endl;
			system("pause");
			return 1;
		}
		cout << societyProtection[i].donation << endl;
	}

	bool state = false;
	cout << "\nGrand Patrons: " << endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (societyProtection[i].donation > 10000)
		{
			cout << societyProtection[i].name << endl;
			state = true;
		} else if (i + 1 == SIZE && state == false)
			cout << "none" << endl;
	}

	state = false;
	cout << "\nPatrons: " << endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (societyProtection[i].donation < 10000)
		{
			cout << societyProtection[i].name << endl;
			state = true;
		} else if (i + 1 == SIZE && state == false)
			cout << "none" << endl;
	}

	delete[] societyProtection;

	system("pause");

	return 0;
}
