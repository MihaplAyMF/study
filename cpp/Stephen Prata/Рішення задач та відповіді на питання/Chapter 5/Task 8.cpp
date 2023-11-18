#include <iostream>
#include <string>

using namespace std;

int main()
{
    char word[200] {};
    int quantityEnterWords {};
   
    cout << "Enter words(to stop, type the word done): ";
    cin >> word;
   
    while (strcmp(word, "done"))
    {
        quantityEnterWords++;
        cin >> word;
    }
    
    cout << "You entered " << quantityEnterWords << " words" << endl;

    return 0;
}
