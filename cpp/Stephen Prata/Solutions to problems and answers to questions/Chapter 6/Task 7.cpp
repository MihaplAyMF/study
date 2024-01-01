#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	const string vowels = "aeiouy";

	string word;
	int vowel {}, consonants {}, others {};

	cout << "Enter words(q to quit): " << endl;
	cin >> word;

	while (word != "q")
	{
		if (vowels.find(tolower(word[0])) != string::npos) // npos = -1, операція пошуку find не знайшла збігу
			vowel++;
		else if (isalpha(word[0]))
			consonants++;
		else
			others++;
		cin >> word;
	}

	cout << "words beginning with vowels: " << vowel << endl;
	cout << "words beginning with consonants: " << consonants << endl;
	cout << "others: " << others << endl;

	return 0;
}
