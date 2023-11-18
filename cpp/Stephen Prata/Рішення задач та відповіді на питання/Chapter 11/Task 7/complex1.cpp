#include "complex1.h"

Complex::Complex()
{
	real = complex = 0;
}

Complex::Complex(double real, double complex)
	: real(real), complex(complex)
{}

Complex Complex::operator+(Complex & cm)
{
	return Complex(real + cm.real, complex + cm.complex);
}

Complex Complex::operator-(Complex& cm)
{
	return Complex(real - cm.real, complex - cm.complex);
}

Complex Complex::operator*(Complex& cm)
{
	return Complex(real * cm.real - complex * cm.complex,
		real * cm.complex + complex * cm.real);
}

Complex Complex::operator~()
{
	return Complex(real, -complex);
}

Complex operator*(double num, Complex& cm)
{
	return Complex(2 * cm.real, 2 * cm.complex);
}

ostream& operator<<(ostream& os, const Complex& cm)
{
	os << "(" << cm.real << ", " << cm.complex << "i)";
	return os;
}

istream& operator>>(istream& is, Complex& cm)
{
	cout << "Real>>";
	(is >> cm.real).get(); 
	if(is.fail())
		return is;
	cout << "Complex>>";
	(is >> cm.complex).get();
	return is;
}
