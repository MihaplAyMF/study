#include <cstring>
#include <cmath>
#include "Vector.h"

using namespace std;

namespace VECTOR 
{	
	const double RadToDeg = 45.0 / atan(1.0);

	Vector::Vector()
	{
		x = y = 0;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{	
		mode = form;
		if(form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if(form == POL)
		{
			x = n1 * std::cos(n2);
			y = n1 * std::sin(n2);
		}
		else
		{
			cout << "Incorrect Ç rdargument to Vector() -- ";
			cout << "vector set to 0 \n";
			x = y = 0;
		}
	}

	void Vector::Reset(double n1, double n2, Mode form)
	{
		mode = form;

		if(form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if(form == POL)
		{
			x = n1 * std::cos(n2);
			y = n1 * std::sin(n2);
		}
		else
		{
			cout << "Incorrect rdargument to Vector() -- ";
			cout << "vector set to 0 \n";
			x = y = 0;
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

	ostream& operator<<(ostream& os, Vector &a)
	{
		if(a.mode == Vector::RECT)
			os << "(x,y) = (" << a.x << ", " << a.y << ")";
		else if(a.mode == Vector::POL)
		{
			os << "(m,a) = (" << a.GetMag() << ", "
				<< a.GetAng() * RadToDeg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}
}

