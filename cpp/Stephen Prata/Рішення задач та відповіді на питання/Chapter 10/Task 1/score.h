#pragma ocne

class Score
{
	string name;
	string score;
	double balance;

public:

	Score();
	Score(string name, string score, double balance);

	void PrintScore();
	void RemoveBalance(double num);
	void AddBalance(double num);
};
