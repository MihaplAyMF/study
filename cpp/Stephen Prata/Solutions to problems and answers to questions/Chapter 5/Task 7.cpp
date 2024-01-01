#include <iostream>
#include <string>

using namespace std;

struct Car
{
    string Name;
    int manufactureYear;
};

int main()
{
    int quantityCar;
    cout << "How many cars to include in the catalog: ";
    (cin >> quantityCar).get();
    
    Car* carCatalog = new Car[quantityCar];

    for (size_t i = 0; i < quantityCar; i++)
    {
        cout << "Car #" << i + 1 << endl;
        cout << "Please enter the make: ";
        getline(cin, carCatalog[i].Name);
        cout << "Please enter the year made: ";
        (cin >> carCatalog[i].manufactureYear).get();
    }
    
    cout << "Here is your collection: ";
    
    for (size_t i = 0; i < quantityCar; i++)
    {
        cout << carCatalog[i].manufactureYear << " " << carCatalog[i].Name << endl;
    }
     
    return 0;
}
