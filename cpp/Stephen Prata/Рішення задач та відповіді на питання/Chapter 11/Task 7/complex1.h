#pragma once
#include <iostream>

using std::ostream;
using std::istream;
using std::cout;
using std::endl;

class Complex
{
private:
	double real;
	double complex;
public:
	Complex();
	Complex(double real, double complex);


	Complex operator+(Complex& cm);
	Complex operator-(Complex& cm);
	Complex operator*(Complex& cm);

	Complex operator~();

	friend Complex operator*(double num, Complex& cm);
	friend ostream& operator<<(ostream& os, const Complex& cm);
	friend istream& operator>>(istream& os, Complex& cm);
};