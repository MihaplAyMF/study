#include "score.h"

Score::Score()
{
	name = "NoName";
	score = "0";
	balance = 0.0;
}

Score::Score(string name, string score, double balance)
{
	this->name = name;
	this->score = score;
	this->balance = balance;
}

void Score::PrintScore()
{
	cout << "Name - " << name << endl
		<< "Score - " << score << endl
		<< "Balance - " << balance << endl;
}

void Score::RemoveBalance(double num)
{
	if(balance > num)
		balance -= num;
	else
		cout << "You don't have enough funds" << endl;

	cout << "Your balance - " << balance << endl;
}

void Score::AddBalance(double num)
{
	balance += num;

	cout << "Your balance - " << balance << endl;
}