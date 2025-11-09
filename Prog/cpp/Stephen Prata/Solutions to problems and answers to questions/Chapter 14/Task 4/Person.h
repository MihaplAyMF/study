#pragma once
#include <string>

class Person
{
private:
	std::string name;
	std::string family;
protected:
	void Data() const;
public:
	Person(std::string name = "", std::string family ="");
	virtual ~Person() = default;
	void SetName(std::string name) { this->name = name; };
	void SetFamily(std::string family) { this->family = family; };
	virtual void Show() const;
	virtual void Set();
};

class Gunslinger : virtual public Person
{
private:
	double time;
	int notches;
protected:
	void Data() const;
	virtual void setData();
public:
	Gunslinger(std::string name = "", std::string family = "", double time = 0, int notche = 0);
	~Gunslinger() = default;
	void SetName(double time) { this->time = time; };
	void SetFamily(int notches) { this->notches = notches; };
	double Draw() { return time; }
	void Show() const;
	void Set() { Person::Set(); Gunslinger::setData(); }
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer(std::string name = "", std::string family = "");
	virtual int Draw() const { return rand() % 52; }
	void Show() const;
	void Set() { Person::Set(); }
};

class BadDude : public PokerPlayer, public Gunslinger
{
public:
	BadDude(std::string name = "", std::string family = "", double time = 0, int notches = 0);
	double Gdraw() { return Gunslinger::Draw(); }
	int Cdraw() { return PokerPlayer::Draw(); }
	void Show() const;
	void Set() { Person::Set(), Gunslinger::setData(); }
};