#include "Cow.h"

Cow::Cow()
{
	name[0] = '\0';
	hobby = nullptr;
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
	: weight(wt)
{
	strcpy(name, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
}

Cow::Cow(const Cow& other)
{
	strcpy(name, other.name);
	hobby = new char[strlen(other.hobby) + 1];
	strcpy(hobby, other.hobby);
	weight = other.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& other)
{
	strcpy(name, other.name);
	hobby = new char[strlen(other.hobby) + 1];
	strcpy(hobby, other.hobby);
	weight = other.weight;
	return *this;
}

void Cow::Show() const
{
	std::cout << "Name: " << name << std::endl
		<< "Hobby: " << hobby << std::endl
		<< "Weight: " << weight << std::endl;
 }

	
