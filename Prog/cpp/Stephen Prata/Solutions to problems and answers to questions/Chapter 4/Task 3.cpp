#include <iostream>
//#include <cstring>

#pragma warning(disable : 4996)

using namespace std;

int main()
{
    const int SIZE = 20;
    char firstName[SIZE];
    char lastName[SIZE];
    char name[40] {};

    cout << "Enter your first name: ";
    cin.getline(firstName, SIZE);
    
    cout << "Enter your last name: ";
    cin.getline(lastName, SIZE);
    
    strcat_s(name, firstName);
    strcat_s(name, ", ");
    strcat_s(name, lastName);

    cout << "Here's the information in а single string: " << name << endl;
    
    return 0;
}
