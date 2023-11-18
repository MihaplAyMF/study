#include <iostream> 
#include "golf.h"

using namespace std;

int main()
{
	golf g1, g2, g3 {"Anyriu"};

	setgolf(g1, "Miha", 4);
	setgolf(g2);
	handicap(g2, 7);
	handicap(g3, 5);

	showgolf(g1);
	showgolf(g2);
	showgolf(g3);
	
	return 0;
}