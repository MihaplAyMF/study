#include <iostream>

using namespace std;

class Person
{
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; }
	Person(const string& ln, const char* fn = "Heyyou")
	{
		lname = ln; 
		strncpy(fname, fn, LIMIT - 1);
	}

	void Show() const
	{
		cout << fname << " " << lname << endl;
	}

	void FormalShow() const
	{
		cout << lname << " " << fname << endl;
	}
};

int main()
{
	Person one;
	Person two("Smythe craft ");
	Person three("Dimwiddy ", "Sam");
	
	cout<< endl;
	one.Show();
	one.FormalShow();

	cout << endl;
	two.Show();
	two.FormalShow();

	cout << endl;
	three.Show();
	three.FormalShow();

	return 0;
}
