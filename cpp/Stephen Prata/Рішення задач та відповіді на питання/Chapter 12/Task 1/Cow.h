#pragma once
#include <iostream>

class Cow
{
private:
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow& other);
	~Cow();
	Cow& operator=(const Cow& other);
	void Show() const;
};