#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Lotto(int maxValue, int count);

int main()
{

    vector<int> winners;
    winners = Lotto(100, 10);

    for(auto val : winners)
    {
        cout << val << " "; 
    }

    return 0;
}

vector<int> Lotto(int maxValue, int count)
{
    if(maxValue < 1 || count < 1 || maxValue < count)
    {
        cerr << "ERROR";
        exit(1);
    }

    vector<int> win, vec;
    for(size_t i = 0; i < maxValue; i++)
    {
        win.push_back(i);
    }
    random_shuffle(win.begin(), win.end());
    
    for(size_t i = 0; i < count; i++)
    {
        vec.push_back(win[i]);
    }
    sort(vec.begin(), vec.end());
    return vec;
}