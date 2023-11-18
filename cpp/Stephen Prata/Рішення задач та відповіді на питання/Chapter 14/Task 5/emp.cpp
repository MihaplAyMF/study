#include "emp.h"

// --- Abstr_emp --- 

Abstr_emp::Abstr_emp()
	: name(""), family(""), job("")
{ }

Abstr_emp::Abstr_emp(const std::string& name, const std::string& family, const std::string& job)
	: name(name), family(family), job(job)
{ }

void Abstr_emp::ShowAll() const
{
	std::cout << "Name: " << name << std::endl
		<< "Family: " << family << std::endl
		<< "Job: " << job << std::endl;
}

void Abstr_emp::SetAll()
{
	std::cout << std::endl << "Enter the first name: ";
	getline(std::cin, name);
	std::cout << "Enter the last name: ";
	getline(std::cin, family);
	std::cout << "Enter the job: ";
	getline(std::cin, job);
}

std::ostream& operator<<(std::ostream& os, const Abstr_emp& other)
{
	os << "\n" << other.name << " " << other.family;
	return os;
}

// --- Employer --- 

Employer::Employer()
	: Abstr_emp("", "", "")
{ }

Employer::Employer(const std::string& name, const std::string& family, const std::string& job)
	: Abstr_emp(name, family, job)
{ }

void Employer::ShowAll() const
{
	std::cout << std::endl << "Status: Employee" << std::endl;
	Abstr_emp::ShowAll();
}

void Employer::SetAll()
{
	Abstr_emp::SetAll();
}

// --- Manager --- 

Manager::Manager()
	: Abstr_emp("", "", ""), inchargeof(0)
{ }

Manager::Manager(const std::string& name, const std::string& family, const std::string& job, int inchargeof)
	: Abstr_emp(name, family, job)
{
	this->inchargeof = inchargeof;
	if(this->inchargeof < 0)
	{
		std::cout << "Error, cannot be in charge of negative people." << std::endl;
		std::cout << "Setting inchargeof to 0" << std::endl;
		this->inchargeof = 0;
	}
}

Manager::Manager(const Abstr_emp & other, int inchargeof)
	: Abstr_emp(other)
{ 
	this->inchargeof = inchargeof;
	if(this->inchargeof < 0)
	{
		std::cout << "Error, cannot be in charge of negative people." << std::endl;
		std::cout << "Setting inchargeof to 0" << std::endl;
		this->inchargeof = 0;
	}
}

Manager::Manager(const Manager & other)
	: Abstr_emp(other), inchargeof(other.inchargeof)
{ }

void Manager::ShowAll() const
{
	std::cout << std::endl << "Status: Manager" << std::endl;
	Abstr_emp::ShowAll();
	std::cout << "In charge of " << inchargeof << " people" << std::endl;
}

void Manager::SetAll()
{
	Abstr_emp::SetAll();
	std::cout << "Enter the number of people the manager is in charge of: ";
	std::cin >> inchargeof;
	while(!std::cin || inchargeof < 0)
	{
		std::cin.clear();
		std::cout << "Error, cannot be in charge of negative people.\nTry again: ";
		std::cin >> inchargeof;
	}
}

// --- Fink ---

Fink::Fink()
	: Abstr_emp("", "", ""), reporsto(reporsto)
{ }

Fink::Fink(const std::string& name, const std::string& family,
	const std::string& job, const std::string& reporsto)
	: Abstr_emp(name, family, job), reporsto(reporsto)
{ }

Fink::Fink(const Abstr_emp & other, const std::string & reporsto)
	: Abstr_emp(other), reporsto(reporsto)
{ }

Fink::Fink(const Fink & other)
	: Abstr_emp(other), reporsto(other.reporsto)
{ }

void Fink::ShowAll() const
{
	std::cout << std::endl << "Status: Fink" << std::endl;
	Abstr_emp::ShowAll();
	std::cout << "Reports to " << reporsto << std::endl;
}

void Fink::SetAll()
{
	Abstr_emp::SetAll();
	std::cout << "Enter whomever is reported to: ";
	getline(std::cin, reporsto);
}

// --- HighFink ---

HighFink::HighFink()
	: Abstr_emp("", "", "")
	, Manager("", "", "", 0)
	, Fink("", "", "", "")
{ }

HighFink::HighFink(const std::string& name, const std::string& family,
	const std::string& job, const std::string& reporsto, int inchargeof)
	: Abstr_emp(name, family, job)
	, Manager(name, family, job, inchargeof)
	, Fink(name, family, job, reporsto)
{ }

HighFink::HighFink(const Abstr_emp & other, const std::string & reporsto, int inchargeo)
	: Abstr_emp(other), Manager(other, inchargeo), Fink(other, reporsto)
{ }

HighFink::HighFink(const Fink & other, int inchargeof)
	: Fink(other), Manager(other, inchargeof)
{ }

HighFink::HighFink(const Manager & other, std::string reporsto)
	: Manager(other), Fink(other, reporsto)
{ }

HighFink::HighFink(const HighFink & other)
	: Abstr_emp(other), Manager(other), Fink(other)
{ }

void HighFink::ShowAll() const
{
	std::cout << std::endl << "Status: HighFink" << std::endl;
	Abstr_emp::ShowAll();
	std::cout << "In charge of " << GetInChargeOf() << "people" << std::endl;
	std::cout << "Reports to " << GetReporsTo() << std::endl;
}

void HighFink::SetAll()
{
	Abstr_emp::SetAll();
	std::cout << "Enter the number of people managed: ";

	while(!std::cin || GetInChargeOf() < 0)
	{
		std::cin.clear();
		std::cout << "Error, cannot be in charge of negative people.\nTry again: ";
		std::cin >> GetInChargeOf();
	}
	std::cin.get();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter whomever is reported to: ";
	getline(std::cin, GetReporsTo());
}
