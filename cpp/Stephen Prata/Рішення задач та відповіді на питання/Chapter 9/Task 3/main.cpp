#include <iostream>
#include <new>

#pragma warning(disable : 4996)

using namespace std;

const int BUF = 512;
int buffer[BUF];

struct staff
{
	char dross[20];
	int slag;
};

//void SetStaff(staff& st);
void PrintStaff(staff& st);


int main()
{
	staff* st = new (buffer) staff[2];

	/*SetStaff(st[0]);
	SetStaff(st[1]);*/
	
	strcpy(st[0].dross, "Test 1"); // о так краще
	st[0].slag = 5;
	strcpy(st[1].dross, "Test 2");
	st[1].slag = 10;

	PrintStaff(st[0]);
	PrintStaff(st[1]);

	return 0;
}


/*void SetStaff(staff& st) // мені лінь
{
	cout << "Enter dross: ";
	cin.get(st.dross, 20);
	cout << "Enter dross: ";
	while (!(cin >> st.slag))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only number! Please enter again: ";
	}
}*/

//void SetStaff(staff& st) // Але тоді будуть однакові(( 
//{ 
//	strcpy(st.dross, "Test");
//	st.slag = 5;
//}

void PrintStaff(staff& st)
{
	cout << "Dross: " << st.dross << endl
		<< "Slag: " << st.slag << endl;
}
