#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	const int SIZE = 4;
	Person* pp[SIZE];

	for(size_t i = 0; i < SIZE; i++)
	{
		cout << "Enter the person category: " << endl;
		cout << "p: person\t g: gunslinger" << endl;
		cout << "k: poker player\t b: bad dude " << endl;
		cout << "q: quite" << endl;
		cout << endl;

		char choice = 0;
		cin >> choice;
		cout << endl;

		while(std::strchr("pgkbq", choice) == NULL)
		{
			std::cout << "Please enter a p, g, k, b, or q: ";
			std::cin >> choice;
		}
		
		cin.get();

		if(choice == 'q')
		{
			break;
		}

		switch(choice)
		{
		case 'p':   pp[i] = new Person;
			break;
		case 'g':   pp[i] = new Gunslinger;
			break;
		case 'k':   pp[i] = new PokerPlayer;
			break;
		case 'b': 	pp[i] = new BadDude;
			break;
		}

		pp[i]->Set();
		pp[i]->Show();

		cout << endl;
	}

	cout << "Your selection:" << std::endl << std::endl;
	for(int i = 0; i < SIZE; i++)
	{
		pp[i]->Show();
		cout << endl;
		delete* (pp + i);
	}
	
	return 0;
}
