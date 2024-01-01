#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Store
{
private:
    ofstream& os;

public:
    Store(ofstream& fout) : os(fout) {}

    void operator()(const string& s)
    {
        size_t len = s.size();
        os.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
        os.write(s.data(), len);
    }
};


void ShowStr(const string& str);
void GetStrs(ifstream& fin, vector<string>& vec);

int main()
{
    vector<string> vostr;
    string temp;

    cout << "Enter string (empty line to quit):\n";
    while(getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // Save to file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Coutld not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";

    for_each(vostr.begin(), vostr.end(), ShowStr);

    return 0;
}

void ShowStr(const string& str)
{
    cout << str << endl;
}

void GetStrs(ifstream& fin, vector<string>& vec)
{
    vec.clear(); // Очищуємо вектор перед заповненням новими даними
    size_t len;
    string temp;

    while(fin.read(reinterpret_cast<char*>(&len), sizeof(size_t)))
    {
        temp.resize(len);
        fin.read(&temp[0], len);
        vec.push_back(temp);
    }
}