#include <iostream>
#include "worker.h"
#include "queue.h"

using namespace std;

const int SIZE = 5;

int main()
{
	Queue<Worker*> q;
	Worker* pw;

	for(int ct = 0; ct < SIZE; ct++)
	{
		cout << "Enter the employee category:\n";
		cout << "w: waiter  s: singer  ";
		cout << "t: singing waiter  q: quit\n";

		char choice = 0;
		cin >> choice;

		while(strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}

		if(choice == 'q')
		{
			break;
		}

		switch(choice)
		{
		case 'w':   pw = new Waiter;
			break;
		case 's':   pw = new Singer;
			break;
		case 't':   pw = new SingingWaiter;
			break;
		}
		cin.get();
		q.Push(pw);
	}

	cout << "\nHere is your staff:\n";

	for(int i = 0; i < q.Size(); i++)
	{
		cout << endl;
		q.Front()->Show();
		q.Pop();
	}
	cout << "Bye." << endl;

	return 0;
}