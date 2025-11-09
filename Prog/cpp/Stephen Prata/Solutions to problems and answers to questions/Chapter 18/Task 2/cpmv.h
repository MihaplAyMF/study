#pragma once

#include <iostream>
#include <string>

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv& other);
	Cpmv(Cpmv&& other);
	~Cpmv();

	Cpmv& operator=(const Cpmv& other);
	Cpmv& operator=(Cpmv&& other);
	Cpmv operator+(const Cpmv& other) const;
	void Display() const;
};