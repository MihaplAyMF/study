#include <iostream>
#include "list.h"

List::List()
	: head(nullptr)
{ }

List::List(const List & other)
{
	Copy(other);
}

List::List(List && other) noexcept
	: head(other.head)
{
	other.head = nullptr;
}

List::~List()
{
	Clear();
}

void List::PushBack(const int& value)
{
	Node* newNode = nullptr; 
	Node* current = head;

	if(head == nullptr)
	{
		head = new Node {value, nullptr};
	}
	else
	{
		while(current->nextNode != nullptr)
			current = current->nextNode;
		current->nextNode = new Node {value, nullptr};
	}
}

void List::PushIndex(const int& value, int index)
{
	if(index >= 0 && index <= Size())
	{
		if(index == 0)
			PushFront(value);
		else if(index == Size())
			PushBack(value);
		else
		{
			Node* current = head;
			Node* prev = nullptr;

			Node* newNode = new Node;
			newNode->data = value;

			for(size_t i = 0; i < index; i++)
			{
				prev = current;
				current = current->nextNode;
			}
			newNode->nextNode = prev->nextNode;
			prev->nextNode = newNode;
		}
	} else 
		cout << "Bad index" << endl;
} 

void List::PushFront(const int& value)
{
	if(head == nullptr)
	{
		head = new Node {value, nullptr};
	}
	else
	{
		Node* current = new Node {value, head};
		head = current;
	}
	
}

void List::PopBack()
{
	if(head != nullptr)
	{	
		if(head->nextNode == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			Node* prev = nullptr;

			while(current->nextNode != nullptr)
			{
				prev = current;
				current = current->nextNode;
			}
			delete current;
			prev->nextNode = nullptr;
		}
	} 
}

void List::PopIndex(int index)
{
	if(index >= 0 && index < Size() - 1)
	{
		if(index == 0)
			PopFront();
		else if(index == Size())
			PopBack();
		else
		{
			Node* current = head;
			Node* prev = nullptr;
			for(size_t i = 0; i < index; i++)
			{
				prev = current;
				current = current->nextNode;
			}
			prev->nextNode = current->nextNode;
			delete current;
			current = nullptr;
		}
	}
}

void List::PopFront()
{
	if(head != nullptr)
	{
		Node* current = head;
		head = head->nextNode;
		delete current;
	}

}

void List::Remove(const int& value)
{
	Node* current = head;
	Node* prev = nullptr;

	while(current != nullptr)
	{
 		if(current->data == value)
		{
			if(prev == nullptr)
			{
				head = head->nextNode;
			} 
			else
			{
				prev->nextNode = current->nextNode;	
			}
			delete current;
			return;
		}
		else
		{
			prev = current;
			current = current->nextNode;
		}
	} 
}

void List::Clear()
{
	while(head != nullptr)
	{
		Node* current = head;
		head = head->nextNode;
		delete current;
	}
	head = nullptr;
}

bool List::Find(const int& value) const
{
	Node* current = head;

	while(current != nullptr)
	{
		if(current->data == value)
		{
			return true;
		}

		current = current->nextNode;
	}

	return false;
}

void List::ShowNode()
{
	if(head == nullptr)
	{
		cout << "List empty";
	}
	
	Node* current = head;
	while(current != nullptr)
	{
		cout << current->data << " ";
		current = current->nextNode;
	}
	cout << endl;
}

bool List::IsEmpty() const
{
	return head == nullptr ? true : false;
}

size_t List::Size() const
{
	size_t i = 0;
	Node* current = head;
	while(current != nullptr)
	{
		i++;
		current = current->nextNode;
	}

	return i;
}

List& List::operator=(const List& other)
{
	if(this != &other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

List& List::operator=(List&& other) noexcept
{

	if(this != &other)
	{
		Clear();

		head = other.head;
		other.head = nullptr;
	}
	return *this;
}

int& List::operator[](size_t index)
{
	if(index >= Size())
	{
		throw std::out_of_range("Incorrect index");
	}

	Node* current = head;

	for(size_t i = 0; i < index; i++)
	{
		current = current->nextNode;
	}

	return current->data;
	
}

const int& List::operator[](size_t index) const
{
	if(index >= Size())
	{
		throw std::out_of_range("Incorrect index");
	}
	Node* current = head;

	for(size_t i = 0; i < index; i++)
	{
		current = current->nextNode;
	}

	return current->data;
}

void List::Copy(const List& other)
{
	if(other.head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		head = new Node {other.head->data, nullptr};

		Node* current = head;
		Node* otherCurrent = other.head;

		while(otherCurrent->nextNode != nullptr)
		{
			current->nextNode = new Node {otherCurrent->nextNode->data, nullptr};

			current = current->nextNode;
			otherCurrent = otherCurrent->nextNode;

		}
	}
}
