#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> met, pet, metAndPet;

    cout << "Met enter your friend (q to quit)." << endl;

    string words;
    while(cin >> words && words != "q")
    {
        met.push_back(words);
    }
    cout << "Pet enter your friend (q to quit)." << endl;

    while(cin >> words && words != "q")
    {
        pet.push_back(words);
    }

    sort(met.begin(), met.end());
    sort(pet.begin(), pet.end());
    
    merge(met.begin(), met.end(), pet.begin(), pet.end(), back_inserter(metAndPet));
    metAndPet.erase(unique(metAndPet.begin(), metAndPet.end()), metAndPet.end());

    for(auto name : metAndPet)
    {
        cout << name << endl;
    }

    return 0;
}