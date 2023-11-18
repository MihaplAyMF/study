#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file;
	file.open("File.txt");
	
	if (!file.is_open())
	{
		cout << "Error opening file" << endl;
		return 1;
	}
	else
	{
		cout << "file \"File.txt\" open successfully" << endl << endl;
	}

	char ch;
	int quantityСharacters {};

	while ((ch = file.get()) != EOF)
	{
		quantityСharacters++;
		cout << (char)ch;
	}

	cout << "\n\nfile has " << quantityСharacters << " characters" << endl;
	
	system("pause");

	return 0; 
}
