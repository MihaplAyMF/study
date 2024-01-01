#include <iostream>

using namespace std;

struct CandyBar
{
    string nameCandy;
    double weight;
    int calories;
};

int main()
{
    CandyBar snack = { "Mocha Munch", 2.5, 350 };
    
    cout << "Candy  characteristics: " << endl;
    cout << "Name - " << snack.nameCandy << endl;
    cout << "Wight - " << snack.weight << endl;
    cout << "Calories - " << snack.calories << endl;

    return 0;
}
