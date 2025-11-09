#pragma once
#include <iostream>

using std::ostream;

namespace VECTOR 
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;

		void SetMag();
		void SetAng();
		void SetX();
		void SetY();

	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		
		void Reset(double x, double y, Mode form = RECT);
		
		~Vector();
		
		double GetX() { return this->x; }
		double Gety() { return this->y; }
		double GetMag() { return this->mag; }
		double GetAng() { return this->ang; }

		void PolarMode() { mode = POL; }
		void RectMode() { mode = RECT; }

		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		friend Vector operator*(double n, const Vector& a);
		friend ostream& operator<<(ostream& os, const Vector& a);

		operator double() const { return mag; };
	};
}
