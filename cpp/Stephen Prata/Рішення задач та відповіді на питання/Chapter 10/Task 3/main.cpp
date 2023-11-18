#include <iostream> 
#include "golf.h"

using namespace std;

int main()
{
	Golf g1, g2; 
	Golf g3 { "Anyriu" };

	g1.SetGolf("Miha", 4);
	g2.SetGolf();
	g2.SetHandicap(7);
	g3.SetHandicap(5);

	g1.ShowGolf();
	g2.ShowGolf();
	g3.ShowGolf();

	return 0;
}