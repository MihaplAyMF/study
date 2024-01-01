#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string filename1;
    cout << "Input name first file: ";
    cin >> filename1; 

    string filename2;
    cout << "Input name second file: ";
    cin >> filename2;

    string filename3;
    cout << "Input name file where output result: ";
    cin >> filename3;

    ifstream fout1(filename1);
    ifstream fout2(filename2);
    ofstream fin(filename3, ios::out | ios::trunc);

    if(!fout1.is_open() || !fout2.is_open() || !fin.is_open())
    {
        cerr << "Could not open the files" << endl;
        return 1;
    }

    string line1, line2;
    while(true)
    {   
        if(fout1.eof() && fout2.eof()) { break; }
        else if(!fout1.eof() && !fout2.eof())
        {
            getline(fout1, line1);
            getline(fout2, line2);
            fin << line1 << " " << line2 << endl;
        }
        else if(!fout1.eof() && fout2.eof())
        {
            getline(fout1, line1);
            fin << line1 << endl;
        }
        else 
        {
            getline(fout2, line2);
            fin << line2 << endl;
        }
    }

    fout1.close();
    fout2.close();
    fin.close();

    return 0;
}
