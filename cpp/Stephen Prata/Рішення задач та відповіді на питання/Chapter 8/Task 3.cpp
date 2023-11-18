#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void SetStr(string& name);

int main()
{
	string str;

	while (true)
	{
		cout << "Enter a strign (q to quit): ";
		getline(cin, str);
		if (str[0] == 'q')
			break;
		SetStr(str);
		cout << str << endl;
	}

	return 0;
}

void SetStr(string& name)
{
	for (size_t i = 0; i < name.length(); i++)
		name[i] = toupper(name[i]);
}
