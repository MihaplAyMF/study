#pragma once

const int Len = 40;

class Golf
{
private:
	char fullname[Len];
	int handicap;
public:
	Golf();
	Golf(const char* name);
	int SetGolf();
	void SetGolf(const char* name);
	void SetGolf(const char* name, int hc);
	void SetHandicap(int hc);
	void ShowGolf() const;
};
