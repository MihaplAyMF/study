#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool CheckPalindrom(string& other);
bool CheckPalindromAlgo(string& other);

int main()
{
	string name = "Madam, i'm Adam";

	cout << CheckPalindrom(name) << endl;
	cout << CheckPalindromAlgo(name) << endl;

	return 0;
}

bool CheckPalindrom(string& other) // Рішення якщо б я не знав що таке контейнери
{
	string str;
	for(size_t i = 0; i < other.size(); i++)
		if(isalpha(other[i]))
			str += tolower(other[i]);

	int size = str.size();
	for(int i = 0; i < size / 2; i++)
	{
		if(str[i] != str[size - i - 1])
			return false;
	}
	return true;
}

bool CheckPalindromAlgo(string& other) // Рішення пов'язане з алгоритмами
{
	string str;
	for(size_t i = 0; i < other.size(); i++)
		if(isalpha(other[i]))
			str.push_back(tolower(other[i]));

	string reversed = str;
	reverse(reversed.begin(), reversed.end());

	return str == reversed;
}
