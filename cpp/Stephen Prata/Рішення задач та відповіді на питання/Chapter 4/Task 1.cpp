#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 80;
    char name_one[SIZE];
    char name_two[SIZE];
    char symb;
    int age;

    cout << "What is your first name? ";
    cin.getline(name_one, SIZE);

    cout << "What is your last name? ";
    cin.getline(name_one, SIZE);
    
    cout << "What letter grade do уои de serve ? ";
    cin >> symb;
    
    cout << "What is your age ? ";
    cin >> age;

    cout << "Name: " << name_one << ", " << name_two << endl;
    cout << "Grade: " << char(symb + 1) << endl;
    cout << "Age: " << age << endl;

    return 0;
}
