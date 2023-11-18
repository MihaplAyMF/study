#include <iostream>
#include <cstring>

#pragma warning(disable : 4996)

using namespace std;

struct stringy
{
	char* str;
	int ct;
};

void set(stringy& name, char* str);
void show(const char* name, int num = 1);
void show(stringy& name, int num = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to bе";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = '6';
	show(testing);
	show(testing, 3);
	show("Done!");

	return 0;
}

void set(stringy& name, char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	name.ct = length; //strlen(str);
	name.str = new char[name.ct + 1];
	strcpy(name.str, str);
}

void show(const char* name, int num)
{
	for (size_t i = 0; i < num; i++)
		cout << name << endl;
}

void show(stringy& name, int num)
{
	for (size_t i = 0; i < num; i++)
		cout << name.str << endl;
}