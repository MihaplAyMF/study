#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{ 
    string filename;
    cout << "Input name file ";
    cin >> filename;
    ofstream fout(filename, ios::out);

    if(!fout.is_open())
    {
        cout << "File could not be open" << endl;
        fout.open(filename, ios::out | ios::trunc);
    } else { cout << "File opened" << endl; }

    cout << "Input text that is written to file: " << endl;
        
    char ch;
    while((ch = cin.get()) != EOF)
        fout << ch;

    cout << "You ender EOF";

    return 0;
}
