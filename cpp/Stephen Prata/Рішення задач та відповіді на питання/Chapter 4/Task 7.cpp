#include <iostream>
#include <string>

using namespace std;

struct Pizza
{
    string nameCompany;
    double diameter;
    double weight;
};

int main()
{
    Pizza pizza;

    cout << "Enter the name of pizza company: ";
    getline(cin, pizza.nameCompany);
    cout << "Enter the diameter of pizza: ";
    cin >> pizza.diameter;
    cout << "Enter the weight of pizza: ";
    cin >> pizza.weight;

    cout << "\nYou enter: " << endl;
    cout << "Name company - " << pizza.nameCompany << endl;
    cout << "Diameter - " << pizza.diameter << endl;
    cout << "Weight - " << pizza.weight << endl;

    return 0;
}
