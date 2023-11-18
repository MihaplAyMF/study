#include <iostream>
#include "Person.h"

void Person::Data() const
{
	std::cout << "Name: "   << name   << std::endl;
	std::cout << "Family: " << family << std::endl;
}

Person::Person(std::string name, std::string family)
	: name(name), family(family)
{}

void Person::Show() const
{
	std::cout << "Type Person" << std::endl;
	Data();
}

void Person::Set()
{
	std::cout << "Enter the first name: ";
	getline(std::cin, name);
	std::cout << "Enter the last name: ";
	getline(std::cin, family);
}

void Gunslinger::Data() const
{
	std::cout << "Draw time: " << time    << std::endl;
	std::cout << "Notches: "   << notches << std::endl;
}

void Gunslinger::setData()
{
	std::cout << "Enter the draw time: ";
	std::cin >> time;
	while(!std::cin || time < 0)
	{
		std::cin.clear();
		std::cout << "Draw time must be a positive number.\nTry again: ";
		std::cin >> time;
	}

	std::cout << "Enter the number of notches: ";
	std::cin >> notches;
	while(!std::cin || notches < 0)
	{
		std::cin.clear();
		std::cout << "Draw time must be a positive integer.\nTry again: ";
		std::cin >> notches;
	}
}

Gunslinger::Gunslinger(std::string name, std::string family, double time, int notches)
	: Person(name, family), time(time), notches(notches)
{ }

void Gunslinger::Show() const
{
	std::cout << "Type Gunslinger" << std::endl;
	Person::Data();
	Data();
}

PokerPlayer::PokerPlayer(std::string name, std::string family)
	: Person(name, family)
{ }

void PokerPlayer::Show() const
{
	std::cout << "Type Poker Player" << std::endl;
	Person::Data();
}

BadDude::BadDude(std::string name, std::string family, double time, int notches)
	: Person(name, family), PokerPlayer(name, family), Gunslinger(name, family, time, notches)
{ }

void BadDude::Show() const
{
	std::cout << "Type BadDude" << std::endl;
	Person::Data();
	Gunslinger::Data();
}
