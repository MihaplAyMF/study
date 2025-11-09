#pragma once
#include <iostream>
#include <cmath>

using std::ostream;

namespace VECTOR 
{
	class Vector
	{
	public:
		enum Mode {RECT, POL};
	private:
		double x;
		double y;
		Mode mode;

	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void Reset(double n1, double n2, Mode form = RECT);
		
		~Vector();
		
		double GetX() { return x; }
		double GetY() { return y; }
		double GetMag() { return sqrt(x * x + y * y); }
		double GetAng() { return atan2(x, y); }

		void PolarMode() { mode = POL; }
		void RectMode() { mode = RECT; }

		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		friend Vector operator*(double n, const Vector& a);
		friend ostream& operator<<(ostream& os, Vector& a);

		operator double() { return GetMag(); }
	};
}
