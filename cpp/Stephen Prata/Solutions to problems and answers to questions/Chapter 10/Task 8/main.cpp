#include <iostream>
#include "list.h"

using namespace std;

int main()
{	

	List listOne, listTwo;
	
	listOne.PushBack(1);
	listOne.PushBack(2);
	listOne.PushBack(3);
	listOne.PushBack(4);

	listOne.ShowNode();

	listTwo = listOne;

	listTwo.ShowNode();

	try
	{
		cout << listOne[10] << endl;
	}
	catch(const std::out_of_range& exc)
	{
		cout << exc.what() << endl;
	}

	return 0;
}
