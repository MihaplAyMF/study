#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word {};
    int quantityEnterWords {};
   
    cout << "Enter words(to stop, type the word done): ";
    cin >> word;
   
    while (word != "done")
    {
        quantityEnterWords++;
        cin >> word;
    }
    
    cout << "You entered " << quantityEnterWords << " words" << endl;

    return 0;
}
