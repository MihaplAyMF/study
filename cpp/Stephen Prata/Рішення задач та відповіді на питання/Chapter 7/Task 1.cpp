#include <iostream>

using namespace std;

void EnterArr(int arr[], int SIZE);
double AverageArr(int arr[], int SIZE);
void PrintArr(int arr[], int SIZE);

int main()
{
    setlocale(LC_ALL, "");

    const int SIZE = 10;
    int arr[SIZE];

    cout << "Для завершення вводу введіть текст або недодатнє число" << endl;
    EnterArr(arr, SIZE);

    cout << endl << "Середня кількість ударів: " << AverageArr(arr, SIZE) << endl;
    cout << "Пораховано за такими результатами: \n";
    PrintArr(arr, SIZE);
    cout << endl;

    return 0;
}

void EnterArr(int arr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Результат " << i + 1 << " гри: ";
        
        while (!(cin >> arr[i]))
        {   
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Only numbers allowed! Enter again: ";
        }

        if (arr[i] <= 0)
            break;

    }
}

double AverageArr(int arr[], int SIZE)
{
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] <= 0)
            return sum / i;
        else
            sum += arr[i];
    }
    return 0;
}

void PrintArr(int arr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] <= 0)
            break;
        else
            cout << arr[i] << " ";
    }
}