#pragma once

template <typename T>
class Stack
{
private:
	T* items;
	int top;

	void Copy(const Stack& other);
	void Move(Stack&& other);
public:
	// --- Constructor ---

	Stack();
	Stack(T value);
	Stack(const Stack& other);
	Stack(Stack&& other);

	// --- Destructor ---

	~Stack();

	// --- Assignment operators ---

	T& operator=(const Stack& other);
	T& operator=(Stack&& other);

	// --- Instert and remove method ---

	void Push(T value);
	void Pop();

	// --- other methos --- 

	T& Top();
	bool IsEmpty();
	size_t Size();
	void Clear();


};

template<typename T>
void Stack<T>::Copy(const Stack& other)
{
	top = other.top;
	items = new T[top];
	for(size_t i = 0; i < top; i++)
	{
		items[i] = other.items[i];
	}
}

template<typename T>
void Stack<T>::Move(Stack&& other)
{
	top = other.top;
	items = other.items;
	other.top = 0;
	items == nullptr;
}

template <typename T>
Stack<T>::Stack()
{
	top = 0;
	items = nullptr;
}

template <typename T>
Stack<T>::Stack(T value)
{
	top = 1;
	items = new T[top];
	items[0] = value;
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
	if(this != other)
	{
		Clear();
		Copy(other);
	}
}

template<typename T>
Stack<T>::Stack(Stack&& other)
{
	if(this != other)
	{
		Clear();
		Move(other);
	}
}

template <typename T>
Stack<T>::~Stack()
{
	Clear();
}

template<typename T>
T& Stack<T>::operator=(const Stack& other)
{
	if(this != other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

template<typename T>
T& Stack<T>::operator=(Stack&& other)
{
	if(this != other)
	{
		Clear();
		Move(other);
	}
	return *this;
}

template<typename T>
void Stack<T>::Push(T value)
{
	top++;
	T* copyItems = items;
	items = new T[top];
	for(size_t i = 0; i < size_t(top-1); i++)
	{
		items[i] = copyItems[i];
	}
	items[top - 1] = value;
	delete[] copyItems;
}

template<typename T>
void Stack<T>::Pop()
{
	if(top == 0)
		return;
	top--;
	T* copyItems = items;
	items = new T[top];
	for(size_t i = 0; i < top; i++)
	{
		items[i] = copyItems[i];
	}
	delete[] copyItems;
}

template<typename T>
T& Stack<T>::Top()
{
	return items[top - 1];
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return top == 0 ? true : false;
}

template<typename T>
inline size_t Stack<T>::Size()
{
	return static_cast<size_t>(top + 1);
}

template<typename T>
void Stack<T>::Clear()
{
	delete[] items;
	top = 0;
}

