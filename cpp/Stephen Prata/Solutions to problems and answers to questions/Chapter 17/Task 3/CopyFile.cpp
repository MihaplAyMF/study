#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string filename1;
    cout << "Input name file: ";
    cin >> filename1; 

    string filename2;
    cout << "Where to copy the file: ";
    cin >> filename2;

    ifstream fout(filename1);
    ofstream fin(filename2, ios::out | ios::trunc);

    if(!fout.is_open() || !fin.is_open())
    {
        cerr << "Could not open the files" << endl;
        return 1;
    }

    string line;
    while(!fout.eof())
    {   
        getline(fout, line);
        fin << line << endl;
    }

    fout.close();
    fin.close();

    return 0;
}
