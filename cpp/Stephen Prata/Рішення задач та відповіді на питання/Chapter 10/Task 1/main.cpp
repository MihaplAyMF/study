#include <iostream>
#include <string>
#include "score.h"

using namespace std;

int main()
{
	Score sco = { "Miha", "03428574", 220 };

	sco.PrintScore();
	sco.AddBalance(100);
	sco.RemoveBalance(50);
	return 0;
}
