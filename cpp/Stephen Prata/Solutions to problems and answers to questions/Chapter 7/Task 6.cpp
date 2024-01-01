#include <iostream>

using namespace std;

int FillArray(double arr[], int SIZE);
void ReverseArray(double arr[], int SIZE);
void ShowArray(double arr[], int SIZE);

int main()
{
    setlocale(LC_ALL, "");

	const int SIZE = 5;
	int newSize;
	double arr[SIZE];

	newSize = FillArray(arr, SIZE);
	ShowArray(arr, newSize);
	
	ReverseArray(arr, newSize);
	ShowArray(arr, newSize);
	
    return 0;
}

int FillArray(double arr[], int SIZE)
{
	int i;
	cout << "Введіть елементи масиву: " << endl;
	for (i = 0; i < SIZE; i++)
	{
		cout << "Елемент #" << i + 1 << ": ";
		if(!(cin >> arr[i]))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return i;
		}
	}
	return i;
}

void ShowArray(double arr[], int SIZE)
{
	cout << "Елементи масиву: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "#" << i + 1 << " - " << arr[i] << endl;
	}
}

void ReverseArray(double arr[], int SIZE)
{
	int temp;
	for (int i = 1; i <= SIZE/2; i++)
	{
		temp = arr[i - 1];
		arr[i - 1] = arr[SIZE - i];
		arr[SIZE - i] = temp;
	}

}