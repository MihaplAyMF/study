#include <cstring>
#include <cmath>
#include "Vector.h"

using namespace std;

namespace VECTOR 
{
	const double RadToDeg = 45.0 / atan(1.0);


	void Vector::SetMag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::SetAng()
	{
		if(x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}

	void Vector::SetX()
	{
		x = mag * cos(ang);
	}

	void Vector::SetY()
	{
		y = mag * sin(ang);
	}


	Vector::Vector()
	{
		x = y = mag = ang = 0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{	
		if(form == RECT)
		{
			x = n1;
			y = n2;
			SetMag();
			SetAng();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / RadToDeg;
			SetX();
			SetY();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0" << endl;
			Vector();
		}
	}

	void Vector::Reset(double n1, double n2, Mode form)
	{
		if(form == RECT)
		{
			x = n1;
			y = n2;
			SetMag();
			SetAng();
		}
		else if(form == POL)
		{
			mag = n1;
			ang = n2 / RadToDeg;
			SetX();
			SetY();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0" << endl;
			Vector();
		}
	}
	
	Vector::~Vector() {}

	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);	
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	ostream& operator<<(ostream& os, const Vector &a)
	{
		if(a.mode == Vector::RECT)
			os << "(x, y) = (" << a.x << ", " << a.y << ")";
		else if(a.mode == Vector::POL)
			os << "(m, a) = (" << a.mag << ", " << a.ang * RadToDeg << ")";
		else
			os << "Vector object mode is invalid";
		return os;
	}
}

