#include "port.h"

Port::Port(const char* br, const char* st, int bot)
	: bottles(bot)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	style = new char[strlen(st) + 1];
	strcpy(style, st);
}

Port::Port(const Port& other)
{
	brand = new char[strlen(other.brand) + 1];
	strcpy(brand, other.brand);
	style = new char[strlen(other.style) + 1];
	strcpy(brand, other.style);
	bottles = other.bottles;
}

Port::~Port()
{
	delete[] brand;
	delete[] style;
}

Port& Port::operator=(const Port& other)
{
	brand = new char[strlen(other.brand) + 1];
	strcpy(brand, other.brand);
	style = new char[strlen(other.style) + 1];
	strcpy(brand, other.style);
	bottles = other.bottles;
	return *this;
}

Port& Port::operator+=(int bot)
{
	bottles += bot;
	return *this;
}

Port& Port::operator-=(int bot)
{
	bottles -= bot;
	return *this;
}

void Port::Show() const
{
	cout << "Brand: " << brand << endl
		<< "Kind: " << style << endl
		<< "Bottles: " << bottles << endl;
}

ostream& operator<<(ostream& os, const Port& other)
{
	os << other.brand << ", " << other.style << ", " << other.bottles << endl;
	return os;
}

VintagePort::VintagePort()
{
	nickname = new char[strlen("none") + 1]; 
	strcpy(nickname, "none");
	year = 0;
}

VintagePort::VintagePort(const char* br, const char* st, const char* nn, int bot, int year)
	: Port(br, st, bot), year(year)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
}

VintagePort::VintagePort(const VintagePort& other)
	: Port(other)
{
	nickname = new char[strlen(other.nickname) + 1];
	strcpy(nickname, other.nickname);
	year = other.year;
}

VintagePort::~VintagePort()
{
	delete[] nickname;
}

VintagePort& VintagePort::operator=(const VintagePort& other)
{
	(*this).Port::operator=(other); 
	nickname = new char[strlen(other.nickname) + 1];
	strcpy(nickname, other.nickname);
	year = other.year;
}

void VintagePort::Show() const
{
	Port::Show();
	cout << "nickname: " << nickname << endl
		<< "year: " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& other)
{
	os << static_cast<const Port&>(other);
	os << "nickname: " << other.nickname << endl
		<< "year: " << other.year << endl;
}
