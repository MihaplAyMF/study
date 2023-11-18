#include <iostream>

using namespace std;

template <typename T>
T Max5(T arr[5])
{
	T max = arr[0];
	for (int i = 1; i < 5; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

int main()
{
	int arrInt[5] {1, 4, 3, 5, 2};
	double arrDouble[5] {1.4, 1.2, 1.5, 1.8, 1.1};

	cout << "Max first arr: " << Max5(arrInt) << endl;
	cout << "Max second arr: " << Max5(arrDouble) << endl;

	return 0;
}
