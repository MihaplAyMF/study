#pragma once
#include <iostream>

using namespace std;

class List
{
private:
	struct Node
	{
		int data;
		Node* nextNode;
	};

	Node* head;

	void Copy(const List& other);
public:

	// --- Constructors ---

	List();
	List(const List& other);
	List(List&& other) noexcept;

	// --- Destructor ---
	
	~List();

	// --- Insert methods ---

	void PushBack(const int& value);
	void PushIndex(const int& value, int index);
	void PushFront(const int& value);

	// --- Remove methods ---

	void PopBack();
	void PopIndex(int index);
	void PopFront();
	void Remove(const int& value);
	void Clear();

	// --- Find method ---
	
	bool Find(const int& value) const;

	// --- Checl size methods ---
	
	bool IsEmpty() const;
	size_t Size() const;

	// --- Assignment operators ---

	List& operator=(const List& other);
	List& operator=(List&& other) noexcept;
	
	// --- Index operators ---

	int& operator[](size_t index);
	const int& operator[](size_t index) const;

	// --- Show method ---

	void ShowNode();

};