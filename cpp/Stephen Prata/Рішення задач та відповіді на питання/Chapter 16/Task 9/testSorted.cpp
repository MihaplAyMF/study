#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	int start_time, end_time;
    vector<int> vi0;

	for(size_t i = 0; i < 1000000; i++)
	{
		vi0.push_back(rand() % 250);
	}
	cout << "Sorting " << 1000000 << " elements" << endl;
	list<int> li1 (vi0.begin(), vi0.end());

	start_time = clock();
	vector<int> vi1(li1.begin(), li1.end());
	sort(vi1.begin(), vi1.end());
	end_time = clock();
	cout << "Sorted vector: "<< (end_time - start_time) << "mc" << endl;

	start_time = clock();
	li1.sort();
	end_time = clock();
	cout << "Sorted list: " << (end_time - start_time) << "mc" << endl;

    return 0;
}

