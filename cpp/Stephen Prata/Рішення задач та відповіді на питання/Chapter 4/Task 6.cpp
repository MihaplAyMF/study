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
    CandyBar snack[3]; 
    
    snack[0] = { "Mocha Munch", 2.5, 350 };
    snack[1] = { "Korovka", 2, 300 };
    snack[2] = { "Clime", 3, 400 };

    cout << "Candy " << endl << endl;

    cout << "One type: " << endl;
    cout << "Name - " << snack[0].nameCandy << endl;
    cout << "Wight - " << snack[0].weight << endl;
    cout << "Calories - " << snack[0].calories << endl << endl;

    cout << "Tow type: " << endl;
    cout << "Name - " << snack[1].nameCandy << endl;
    cout << "Wight - " << snack[1].weight << endl;
    cout << "Calories - " << snack[1].calories << endl << endl;

    cout << "Three type: " << endl;
    cout << "Name - " << snack[2].nameCandy << endl;
    cout << "Wight - " << snack[2].weight << endl;
    cout << "Calories - " << snack[2].calories << endl << endl;

    return 0;
}
