#include <iostream>

using namespace std;

struct CandyBar
{
	const char* name;
	double weight;
	int calories;
};

void SetCandy(CandyBar& candy, const char* name = "Millennium Munch", double weight = 2.85, int calories = 350);
void PrintCandy(CandyBar& candy);

int main()
{

	CandyBar box_1;
	CandyBar box_2;
	CandyBar box_3;

	SetCandy(box_1);
	PrintCandy(box_1);

	SetCandy(box_2, "Rafaello", 2.5, 8000);
	PrintCandy(box_2);

	SetCandy(box_3, "Bon-Bon", 2.7);
	PrintCandy(box_3);

	return 0;
}

void SetCandy(CandyBar& candy, const char* name, double weight, int calories)
{
	candy.name = name;
	candy.weight = weight;
	candy.calories = calories;
}

void PrintCandy(CandyBar& candy)
{
	cout << "Cand name: " << candy.name << endl
		<< "Weight: " << candy.weight << endl
		<< "Calories: " << candy.calories << endl;
}
