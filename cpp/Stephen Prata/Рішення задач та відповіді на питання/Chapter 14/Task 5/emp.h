#pragma once
#include <iostream>
#include <string>

class Abstr_emp
{
private:
	std::string name;
	std::string family;
	std::string job;
public:
	Abstr_emp();
	Abstr_emp(const std::string& name, const std::string& family,
			  const std::string& job);
	virtual void ShowAll() const;
	virtual void SetAll();
	friend std::ostream& operator<<(std::ostream& os, const Abstr_emp& other);
	virtual ~Abstr_emp() { };
};

class Employer : public Abstr_emp
{
public:
	Employer();
	Employer(const std::string& name, const std::string& family,
			 const std::string& job);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class Manager : virtual public Abstr_emp
{
private:
	int inchargeof;
protected:
	int GetInChargeOf() const { return inchargeof; }
	int& GetInChargeOf() { return inchargeof; }
public:
	Manager();
	Manager(const std::string& name, const std::string& family,
			const std::string& job, int inchargeof = 0);
	Manager(const Abstr_emp& other, int inchargeof	);
	Manager(const Manager& other);

	virtual void ShowAll() const;
	virtual void SetAll();
};

class Fink : virtual public Abstr_emp
{
private:
	std::string reporsto;
protected:
	const std::string GetReporsTo() const { return reporsto; }
	std::string& GetReporsTo() { return reporsto; }
public:
	Fink();
	Fink(const std::string& name, const std::string& family,
		 const std::string& job, const std::string& reporsto);
	Fink(const Abstr_emp& other, const std::string& reporsto);
	Fink(const Fink& other);

	virtual void ShowAll() const;
	virtual void SetAll();
};

class HighFink : public Manager, Fink
{
public:
	HighFink();
	HighFink(const std::string& name, const std::string& family,
			 const std::string& job, const std::string& reporsto, int inchargeof);
	HighFink(const Abstr_emp& other, const std::string& reporsto, int inchargeo);
	HighFink(const Fink& other, int inchargeof);
	HighFink(const Manager& other, std::string reporsto);
	HighFink(const HighFink& other);

	virtual void ShowAll() const;
	virtual void SetAll();
};
