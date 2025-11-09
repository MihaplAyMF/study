#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10); 
    list<int> etcetera(vals, vals + 10);

    auto outline = [](int n) { std::cout << n << " "; };

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outline);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outline);
    cout << endl;
    yadayada.remove_if([](int v) { return v > 100; });
    etcetera.remove_if([](int v) { return v > 200; });
    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outline);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outline);
    cout << endl;

    return 0;
}
