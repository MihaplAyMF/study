#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char ch;

    while ((ch = cin.get()) != '@')
    {
        if (!isdigit(ch))
        {
            if (islower(ch))
                cout << char(toupper(ch));
            else if (isupper(ch))
                cout << char(tolower(ch));
            else
                cout << ch;
        }
    }

    return 0;
}