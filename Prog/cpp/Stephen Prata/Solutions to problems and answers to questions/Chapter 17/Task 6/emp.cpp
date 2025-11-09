#include "emp.h"

// --- Abstr_emp --- 

#pragma region Abstract 

Abstr_emp::Abstr_emp()
	: name(""), family(""), job("")
{ }

Abstr_emp::Abstr_emp(const std::string& name, const std::string& family, const std::string& job)
	: name(name), family(family), job(job)
{ }

void Abstr_emp::ShowAll() const
{
	std::cout << std:: endl << "Name: " << name << std::endl
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

void Abstr_emp::WriteType(std::ofstream& fout, int type)
{
	fout.write(reinterpret_cast<const char*>(&type), sizeof(int));
}
void Abstr_emp::WriteData(std::ofstream& fout)
{
	int length = static_cast<int>(name.size());
	fout.write(reinterpret_cast<const char*>(&length), sizeof(int));
	fout.write(name.c_str(), length);

	length = static_cast<int>(family.size());
	fout.write(reinterpret_cast<const char*>(&length), sizeof(int));
	fout.write(family.c_str(), length);

	length = static_cast<int>(job.size());
	fout.write(reinterpret_cast<const char*>(&length), sizeof(int));
	fout.write(job.c_str(), length);
}

void Abstr_emp::ReadFromStream(std::ifstream& fin)
{
	int length = 0;
	fin.read(reinterpret_cast<char*>(&length), sizeof(int));
	name.resize(length);
	fin.read(&name[0], length);

	fin.read(reinterpret_cast<char*>(&length), sizeof(int));
	family.resize(length);
	fin.read(&family[0], length);

	fin.read(reinterpret_cast<char*>(&length), sizeof(int));
	job.resize(length);
	fin.read(&job[0], length);
}

void Abstr_emp::WriteToStream(std::ofstream& fout)
{
	WriteType(fout, 1);
	WriteData(fout);
}

std::ostream& operator<<(std::ostream& os, const Abstr_emp& other)
{
	os << "\n" << other.name << " " << other.family;
	return os;
}

#pragma endregion Abstract

// --- Employer --- 

#pragma region Employer  

Employer::Employer()
	: Abstr_emp("", "", "")
{
}

Employer::Employer(const std::string& name, const std::string& family, const std::string& job)
	: Abstr_emp(name, family, job)
{
}

void Employer::ReadFromStream(std::ifstream& fin)
{
	Abstr_emp::ReadFromStream(fin);
}

void Employer::WriteToStream(std::ofstream& fout)
{
	Abstr_emp::WriteType(fout, 1);
	Abstr_emp::WriteData(fout);
}

void Employer::ShowAll() const
{
	std::cout << std::endl << "Status: Employee";
	Abstr_emp::ShowAll();
}

void Employer::SetAll()
{
	Abstr_emp::SetAll();
}

#pragma endregion Abstract 

// --- Manager --- 

#pragma region Manager   

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

void Manager::ReadFromStream(std::ifstream& fin)
{
	Abstr_emp::ReadFromStream(fin);
	fin.read(reinterpret_cast<char*>(&inchargeof), sizeof(int));
}

void Manager::WriteToStream(std::ofstream& fout)
{
	Abstr_emp::WriteType(fout, 2);
	Abstr_emp::WriteData(fout);
	fout.write(reinterpret_cast<const char*>(&inchargeof), sizeof(int));
}

void Manager::ShowAll() const
{
	std::cout << std::endl << "Status: Manager";
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
	std::cout << std::endl;
}

#pragma endregion Manager   

// --- Fink ---

#pragma region Fink  

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

void Fink::ReadFromStream(std::ifstream& fin)
{
	Abstr_emp::ReadFromStream(fin); 
	size_t length;
	fin.read(reinterpret_cast<char*>(&length), sizeof(size_t));
	reporsto.resize(length);
	fin.read(&reporsto[0], length);
}

void Fink::WriteToStream(std::ofstream& fout)
{
	Abstr_emp::WriteType(fout, 3);
	Abstr_emp::WriteData(fout); 
	size_t length = reporsto.size();
	fout.write(reinterpret_cast<const char*>(&length), sizeof(size_t));
	fout.write(reporsto.c_str(), length);
}

void Fink::ShowAll() const
{
	std::cout << std::endl << "Status: Fink";
	Abstr_emp::ShowAll();
	std::cout << "Reports to " << reporsto << std::endl;
}

void Fink::SetAll()
{
	Abstr_emp::SetAll();
	std::cout << "Enter whomever is reported to: ";
	getline(std::cin, reporsto);
	std::cout << std::endl;
}

#pragma endregion Fink  

// --- HighFink ---

#pragma region HighFink

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

HighFink::HighFink(const Abstr_emp & other, const std::string & reporsto, int inchargeof)
	: Abstr_emp(other), Manager(other, inchargeof), Fink(other, reporsto)
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

void HighFink::ReadFromStream(std::ifstream& fin)
{
	Abstr_emp::ReadFromStream(fin);

	size_t length;
	fin.read(reinterpret_cast<char*>(&length), sizeof(size_t));
	GetReporsTo().resize(length);
	fin.read(&GetReporsTo()[0], length);

	fin.read(reinterpret_cast<char*>(&GetInChargeOf()), sizeof(int));
}

void HighFink::WriteToStream(std::ofstream& fout)
{
	Abstr_emp::WriteType(fout, 4);
	Abstr_emp::WriteData(fout);

	size_t length = GetReporsTo().size();
	fout.write(reinterpret_cast<const char*>(&length), sizeof(size_t));
	fout.write(GetReporsTo().c_str(), length);
	//int inchargeof = GetInChargeOf();
	fout.write(reinterpret_cast<const char*>(&GetInChargeOf()), sizeof(int));
}

void HighFink::ShowAll() const
{
	std::cout << std::endl << "Status: HighFink";
	Abstr_emp::ShowAll();
	std::cout << "In charge of " << GetInChargeOf() << " people" << std::endl;
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

#pragma endregion HighFink