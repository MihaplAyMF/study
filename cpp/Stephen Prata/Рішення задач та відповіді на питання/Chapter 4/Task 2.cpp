#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    string dessert;

    cout << "Enter your name: ";
    getline(cin, name); 
 
    cout << "Enter your favorite dessert: ";
    getline(cin, dessert);
    
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << "." << endl;
    
    return 0;
}
