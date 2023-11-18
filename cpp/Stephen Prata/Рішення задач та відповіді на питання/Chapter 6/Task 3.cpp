#include <iostream>

using namespace std;

int main()
{
	char ch;
	
	cout << "Please enter one of the following choices: " << endl;
	cout << "c) carnivore\tp) pianist" << endl;
	cout << "t) tree\tg) game" << endl;
	cout << "q) end program" << endl << ": ";

	cin.get(ch).get();

	while (ch != 'q' && ch != 'Q')
	{
		switch (ch)
		{
			case 'c':
			case 'C':
				cout << "You enter c" << endl << ": ";
				break;
			case 'p':
			case 'P':
				cout << "You enter p" << endl << ": ";
				break;
			case 't':
			case 'T':
				cout << "You enter t" << endl << ": ";
				break;
			case 'g':
			case 'G':
				cout << "You enter g" << endl << ": ";
				break; 
			default:
				cout << "Please enter а с, р, t, or g: ";
				cin.get(ch).get(); continue;
				break;
		}
		cin.get(ch).get();
	}

    return 0;
}