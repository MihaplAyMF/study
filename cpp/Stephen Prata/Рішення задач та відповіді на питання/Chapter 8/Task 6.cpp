#include <iostream>

using namespace std;

template <typename T>
T Maxn(T arr[], int n);

template <>
const char* Maxn<const char*>(const char* arr[], int n);

int main()
{
	int arrInt[6] {1, 4, 3, 6, 2, 5};
	double arrDouble[4] {1.4, 1.2, 1.8, 1.1};
	const char* name[5] = { "Computer", "Table", "Board", "Cubik", "Desktop" }; 

	cout << "Max int number: " << Maxn(arrInt, 6) << endl;
	cout << "Max double number: " << Maxn(arrDouble, 4) << endl;
	cout << "Max str: " << Maxn(name, 5) << endl;

	return 0;
}

template <typename T>
T Maxn(T arr[], int n)
{
	T max = arr[0];
	for (int i = 1; i < n; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

template <> 
const char* Maxn<const char*>(const char* arr[], int n)
{
	const char* maxStr = arr[0];
	int max = strlen(maxStr);

	for (int i = 1; i < n; i++)
	{
		if (max < strlen(arr[i])) 
		{
			maxStr = arr[i];
			max = strlen(maxStr);
		}
	}
	return maxStr;
}