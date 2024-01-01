#include <iostream>

using namespace std;

int num = 0;

void Print(const char* str, int num = 0);

int main()
{
	Print("sdfsdf");
	Print("Test");
	Print("А так?");
	Print("Ahaha", 3);

	return 0;
}

void Print(const char* str, int n)
{
	if (n != 0)
		for (size_t i = 0; i < num; i++)
			cout << str << endl;
	else 
		cout << str << endl;
	num++;
}