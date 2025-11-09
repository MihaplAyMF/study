#include <iostream>

using namespace std;

long double sum_values(const long double& element)
{
    return element;
}

template <typename ... Args>
long double sum_values(const long double& element, const Args& ... arguments)
{
    return element + sum_values(arguments...);
}

int main()
{
    long double value = sum_values(2, 4, 5, 123.23, 'd');
    
    cout << value << endl;
    
    return 0;
}