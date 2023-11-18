#include <iostream>
#include <string>

using namespace std;

void strcount(const char* str);
void strcount(string str);

const int ArSize = 10;

int main()
{
   
    
    string str;
    char next;
    
    cout << "Enter a line:\n";
    getline(cin, str);
    
    while (cin)
    {

        strcount(str);
        cout << "Enter next line (empty line to quit):\n";
       
        getline(cin, str);
    }
    
    cout << "Bye\n";
 
    
    /*char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);

    while (cin)
    {
        cin.get(next);
        while (next != '\n')
               cin.get(next);
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye\n";*/

    return 0;
}

void strcount(const char* str)
{
    static int total = 0;
    int count = 0;

    cout << "\"" << str << "\" contains ";
    while (*str++)
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}

void strcount(string str)
{
    static int total = 0;
    int count = 0;

    cout << "\"" << str << "\" contains ";
    count = str.length();
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
