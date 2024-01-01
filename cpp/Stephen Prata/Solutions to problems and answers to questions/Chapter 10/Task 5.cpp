#include <iostream>

using namespace std;

struct Customer
{
	string name;
	double paument;
};

typedef Customer Item;

class Stack
{
	enum {MAX = 10};
	Item items[MAX];
	int top {};
public:
	
	Stack() {};

	bool isempty() const 
	{
		return (top == 0) ? true : false;
	}
	
	bool isfull() const 
	{
		return (top == MAX) ? true : false;
	}

	bool push(Item& item) // добавити в стек
	{ 
		if (!isfull())
		{
			cout << item.name << " " << item.paument << " " << top + 1 << endl;
			items[top++] = item;
			return true;
		} else
			return false;
	}

	bool pop(Item& item) // видалити зі стеку
	{
		if (!isempty())
		{
			item = items[--top];
			cout << item.name << " " << item.paument << " " << top + 1 << endl;
			return true;
		} else
			return false;
		
	}
};

int main()
{
	Stack st;
	Item po;
	Item n1 { "Mykhailo", 200 };
	Item n1 { "Vika", 400 };
	Item n1 { "Taras", 150 };

	st.push(n1);
	st.push(n2);
	st.push(n3);
	
	st.pop(po);
	st.pop(po);
	st.pop(po);

	st.push(n1);
	st.push(n2);
	st.push(n1);
	st.push(n3);
	st.push(n1);

	st.pop(po);
	st.pop(po);
	st.pop(po);
	st.pop(po);
	st.pop(po);

	return 0;
}
