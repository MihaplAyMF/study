#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

int reduce(int ar[], int n);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    constexpr int size = 10;
    int arr[size];

    for(size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }
    cout << endl;
   
    const int newSize = reduce(arr, size);

    for(size_t i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

int reduce(int ar[], int n){ 
 
    sort(ar, ar + n);
    int size = unique(ar, ar + n) - ar;

    return size;
}
