#include <iostream>

using namespace std;

long double probability(unsigned numbers, unsigned picks);

int main()
{
    setlocale(LC_ALL, "");

    double main_field = 47, mega_field = 27;
 
    cout << "You have one chance in ";
    cout << probability(main_field, 5) * probability(mega_field, 1);
    cout << " of winning.\n";
    
    cout << "bye\n";

    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;  
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}
