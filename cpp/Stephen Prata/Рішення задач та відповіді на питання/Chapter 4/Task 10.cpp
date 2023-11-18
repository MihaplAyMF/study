#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<double, 3> races;

    cout << "Enter the first result of the 40m race: ";
    cin >> races[0]; 
    cout << "Enter the second result of the 40m race: ";
    cin >> races[1]; 
    cout << "Enter the third result of the 40m race: ";
    cin >> races[2];

    cout << "\nYour races: " << endl;
    cout << "First - " << races[0] << endl;
    cout << "Second - " << races[1] << endl;
    cout << "Third - " << races[2] << endl;
    cout << "Average result - " << (races[0]+ races[1] + races[2])/races.size() << endl;

    return 0;
}
