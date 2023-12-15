#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

template <class Т>
int reduce(Т ar[], int n);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    constexpr int size = 10;
    int arrInt[size]; 
    string arrStr[size];

    for(size_t i = 0; i < size; i++)
    {
        arrInt[i] = rand() % 10;
        cout << arrInt[i] << " ";
    }
    cout << endl;
 
    ifstream file("words.txt");
    if(!file.is_open())
    {
        std::cerr << "Unable to open the file." << std::endl;
        exit(1);
    }
    
    string word;
    for(size_t i = 0; i < size; i++)
    {
        file >> word;
        arrStr[i] = word;
        cout << arrStr[i] << " ";
    }
    cout << endl;

    const int newSizeInt = reduce(arrInt, size);
    const int newSizeStr = reduce(arrStr, size);

    for(size_t i = 0; i < newSizeInt; i++)
    {
        cout << arrInt[i] << " ";
    }    
    
    cout << endl;
    for(size_t i = 0; i < newSizeStr; i++)
    {
        cout << arrStr[i] << " ";
    }

    return 0;
}

template <class Т>
int reduce(Т ar[], int n)
{ 
    sort(ar, ar + n);
    int size = unique(ar, ar + n) - ar;
    cout << size << endl;
    return size;
}
