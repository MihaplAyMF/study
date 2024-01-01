#include <iostream>
#include <valarray>
#include <string>

using namespace std;

class Wine : public string
{
private:
    int year;
    pair<valarray<int>, valarray<int>> myPair;
public:
    Wine(string l, int y, const int yr[], const int bot[])
        : string(l), year(y)
    {
        myPair.first = valarray<int>(yr, y);
        myPair.second = valarray<int>(bot, y);
    }
    Wine(string l, int y)
        : string(l), year(y)
    { 
        myPair.first = valarray<int>(y);
        myPair.second = valarray<int>(y);
    }

    string& Label()
    {
        return static_cast<string&>(*this);
    }

    void SetBottles()
    {
        cout << "Enter" << (const string&)*this << " data for " << year << " year(s): " << endl;
        int y, count;
        for(size_t i = 0; i < year; i++)
        {
            cout << "Enter year: ";
            cin >> y;
            cout << "Enter bottles for tha year: ";
            cin >> count;
            myPair.first[i] = y;
            myPair.second[i] = count;
        }
    }
    int Sum()
    {
        return myPair.second.sum();
    }
    void Show()
    {
        cout << "Wine: " << (const string&)*this << endl;
        cout << "\tyear\tbottles" << endl;
        for(size_t i = 0; i < year; i++)
        {
            cout << "\t" << myPair.first[i] << "\t" << myPair.second[i] << endl;
        }
    }
};

int main()
{
    string label;
    cout << "Enter name of wine: ";
    getline(cin, label);
    int year;
    cout << "Enter number of years: ";
    cin >> year;
    Wine holding(label, year);
    holding.SetBottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total boottles for " << more.Label()
        << ": " << more.Sum() << endl;
    cout << "Bye" << endl;

    return 0;
}
