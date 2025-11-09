#include <iostream>
#include "emp.h"

using namespace std;

int main()
{
	Employer em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	Manager ma("Amorphia", "Spindragon ", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	Fink fi("Matt", "Oggs ", "Oiler", "Juno Barr" );
	cout << fi << endl;
	fi.ShowAll();
	HighFink hf(ma, "Curly kew");
	hf.ShowAll();
	cout << "Press a key for next phase: " << endl;
	cin.get();  
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	HighFink hf2;
	hf2.SetAll();
	cout << endl << "Using an Abstr_emp* pointer: " << endl;
	Abstr_emp* tri[4] = {&em, &fi, &hf, &hf2};
	for(size_t i = 0; i < 4; i++)
	{
		tri[i]->SetAll();
	}

	return 0;
}
