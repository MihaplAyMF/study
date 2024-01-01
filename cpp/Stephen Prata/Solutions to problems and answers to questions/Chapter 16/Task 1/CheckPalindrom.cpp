#include <iostream>
#include <algorithm>

using namespace std;

bool CheckPalindrom(string& other);
bool CheckPalindromAlgo(string& other);

int main()
{
	string name = "atta";

	cout << CheckPalindrom(name);

	return 0;
}

bool CheckPalindrom(string& other) // Рішення якщо б я не знав що таке контейнери
{
	int size = other.size();
	for(int i = 0; i < size / 2; i++)
	{
		if(other[i] != other[size - i - 1])
			return false;
	}
	return true;
}

bool CheckPalindromAlgo(string& other) // Рішення пов'язане з алгоритмами
{
	string reversed = other;
	reverse(reversed.begin(), reversed.end());

	return other == reversed;
}

