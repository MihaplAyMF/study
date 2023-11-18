#include <iostream>

using namespace std;

class Move
{
private: 
	double x;
	double y;
public:
	Move(double a = 0, double b = 0)
	{
		x = a; 
		y = b;
	}
	void ShowMove() const
	{
		cout << "\nx - " << x << endl;
		cout << "y - " << y << endl;
	}
	Move Add(const Move& m) const
	{
		Move m2;
		m2 = x + m.x;
		m2 = y + m.y;
		return m2;
	}
	void Reset(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}

};

int main()
{
	Move objOne { 2, 5 };
	Move objTwo { 7, 2 };

	objOne.ShowMove();
	objTwo.ShowMove();
	objOne.Add(objTwo); 
	objOne.ShowMove();

	objOne.Reset(2, 5);
	objOne.ShowMove();

	return 0;
}
