#include <iostream>
#include <cstring>
#include <string>

#pragma warning(disable : 4996)

using namespace std;

int main()
{
    string firstName;
    string lastName;
    string name;

    cout << "Enter your first name: ";
    getline(cin, firstName);
    
    cout << "Enter your last name: ";
    getline(cin, lastName);
    
    name = firstName + ", " + lastName;

    cout << "Here's the information in а single string: " << name << endl;
    
    return 0;
}
