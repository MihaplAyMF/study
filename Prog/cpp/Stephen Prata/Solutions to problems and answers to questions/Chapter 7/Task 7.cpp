#include <iostream>

using namespace std;

int FillArray(double* begin , double* end);
void ShowArray(const double* begin, double* end);
void Revalue(double r, double* begin, double* end);

const int Max = 5;

int main()
{
    double properties[Max];

    int size = FillArray(properties, properties+Max);
    ShowArray(properties, properties + size);

    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))  
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bad input; Please enter a number: ";
        }
        Revalue(factor, properties, properties + size);
        ShowArray(properties, properties + size);
    }
    cout << "Done.\n";

    return 0;
}

int FillArray(double* begin, double* end)
{
    double temp;
    int i;
    for (i = 0; i < end - begin; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        if (!(cin >> temp))   
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bad input; input process terminated.\n";
            break;
        } else if (temp < 0)     
            break;
        begin[i] = temp;
    }
    return i;
}

void ShowArray(const double* begin, double* end)
{
    for (int i = 0; i < end - begin; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << begin[i] << endl;
    }
}

void Revalue(double r, double* begin, double* end)
{
    double* parr;
    for (parr = begin; begin < end; begin++)
        *begin *= r;
}
