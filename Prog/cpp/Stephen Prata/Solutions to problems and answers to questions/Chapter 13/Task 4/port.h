#pragma once
#include <iostream>

using namespace std;

class Port
{
private:
	char* brand;
	char* style;
	int bottles;
public:
	Port(const char* br = "none", const char* st = "none", int bot = 0);
	Port(const Port& other);
	virtual ~Port();
	Port& operator=(const Port& other);
	Port& operator+=(int bot);
	Port& operator-=(int bot);
	int BootleCount() const { return bottles; }
	virtual void Show() const;
	friend ostream& operator<<(ostream& os, const Port& other);
};

class VintagePort : public Port
{
private:
	char* nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* br = "none", const char* st = "none", const char* nn = "none", int bot = 0, int year = 0);
	VintagePort(const VintagePort& other);
	~VintagePort(); 
	VintagePort& operator=(const VintagePort& other);
	void Show() const;
	friend ostream& operator<<(ostream & os, const VintagePort & other);
};