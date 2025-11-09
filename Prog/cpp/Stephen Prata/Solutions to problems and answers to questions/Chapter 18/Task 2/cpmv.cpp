#include "cpmv.h"

Cpmv::Cpmv()
{
	std::cout << "default constructor" << std::endl;

	pi = new Info {"", ""};
}

Cpmv::Cpmv(std::string q, std::string z)
	: pi(new Info{q, z})
{
	std::cout << "constructor with 2 param" << std::endl;
}

Cpmv::Cpmv(const Cpmv& other)
{
	std::cout << "copy constructor" << std::endl;
	pi = new Info {other.pi->qcode, other.pi->zcode};
}

Cpmv::Cpmv(Cpmv&& other)
{
	std::cout << "move constructor" << std::endl;

	pi = other.pi;
	other.pi = nullptr;
}

Cpmv::~Cpmv()
{
	std::cout << "destructor" << std::endl;
	delete pi;
}

Cpmv& Cpmv::operator=(const Cpmv& other)
{
	std::cout << "copy assignment operator" << std::endl;
	if(this != &other) 
	{
		delete pi;
		pi = new Info {other.pi->qcode, other.pi->zcode};
	}
	
	return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& other)
{
	std::cout << "copy assignment operator" << std::endl;
	if(this != &other)
	{
		pi = other.pi;
		other.pi = nullptr;
	}
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv& other) const
{
	Cpmv temp;

	temp.pi->qcode = pi->qcode + other.pi->qcode;
	temp.pi->zcode = pi->zcode + other.pi->zcode;

	return temp;
}

void Cpmv::Display() const
{
	std::cout << "qcode = " << pi->qcode << std::endl;
	std::cout << "zcode = " << pi->zcode << std::endl;
}
