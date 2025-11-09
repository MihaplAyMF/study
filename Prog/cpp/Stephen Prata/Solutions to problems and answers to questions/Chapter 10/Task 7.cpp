#include <iostream>

using namespace std;

const int LIMIT = 19;

class Plorg
{
	
	char name[LIMIT];
	int pleasure;
public:

	Plorg(const char* name = "Plorga", int pleasure = 50)
	{
		strncpy(this->name, name, LIMIT - 1);
		this->pleasure = pleasure;
	}
	void ShowPlorg()
	{
		cout << "Plorg name - " << name << endl
			<< "pleasure index - " << pleasure << endl;
	};
	void SetPleasure(int pleasure)
	{
		this->pleasure = pleasure;
	}
};

int main()
{
	Plorg d;
	d.ShowPlorg();

	Plorg b {"dsfsdf"};
	b.ShowPlorg();

	return 0;
}
