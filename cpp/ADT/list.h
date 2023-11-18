#pragma once

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* nextNode;
	};

	Node* head;
	Node* tail;
	size_t size;

	void Copy(const List& other); 
public:
	class Iterator
	{
	public:
		Iterator(Node* node);

		bool operator!=(const Iterator& other) const;
		Iterator& operator++();   // i++ -> i.operator++()  префіксний
		Iterator operator++(int); // ++i -> i.operator++(1) постфіксний
		T& operator*();
	private:
		Node* node;
	};

	// --- Constructors ---

	List();
	List(const List& other);
	List(List&& other) noexcept;

	// --- Destructor ---
	
	~List();

	// --- Insert methods ---

	void PushBack(const T& value);
	void PushIndex(const T& value, int index);
	void PushFront(const T& value);

	// --- Remove methods ---

	void PopBack();
	void PopIndex(T index);
	void PopFront();
	void Remove(const T& value);
	void Clear();

	// --- Find method ---
	
	bool Find(const T& value) const;

	// --- Checl size methods ---
	
	bool IsEmpty() const;
	size_t Size() const;

	// --- Assignment operators ---

	List& operator=(const List& other);
	List& operator=(List&& other) noexcept;

	// --- Iterator method --- //
	
	Iterator Begin();
	Iterator End();
	  
};

template <typename T>
void List<T>::Copy(const List<T>& other)
{
	if(other.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
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

		tail = current;
		size = other.size;
	}
}

template <typename T>
List<T>::List()
	: head(nullptr), tail(nullptr), size(0)
{
}

template <typename T>
List<T>::List(const List<T>& other)
	: head(nullptr), tail(nullptr), size(0)
{
	Copy(other);
}

template <typename T>
List<T>::List(List<T>&& other) noexcept
	: head(other.head), tail(other.tail), size(other.size)
{
	other.head = nullptr;
	other.tail = nullptr;
	other.size = 0;
}

template<typename T>
List<T>::~List()
{
	Clear();
}

template <typename T>
void List<T>::PushBack(const T& value)
{
	size++;
	if(tail == nullptr)
	{
		head = new Node {value, nullptr};
		tail = head;
	}
	else
	{
		Node* current = tail;
		current->nextNode = new Node {value, nullptr};
		tail = current->nextNode;
	}

}

template <typename T>
void List<T>::PopBack()
{
	if(head != nullptr)
	{
		size--;
		if(head->nextNode == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
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
			tail = prev;
		}
	}
}

template <typename T>
void List<T>::Clear()
{
	while(head != nullptr)
	{
		Node* current = head;
		head = head->nextNode;
		delete current;
	}
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <typename T>
void List<T>::PushIndex(const T& value, int index)
{
	if(index >= 0 && index <= size)
	{
		if(index == 0)
			PushFront(value);
		else if(index == size)
			PushBack(value);
		else
		{
			size++;
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
	}
}

template <typename T>
void List<T>::PushFront(const T& value)
{
	size++;
	if(head == nullptr)
	{
		head = new Node {value, nullptr};
		tail = head;
	}
	else if(tail == head)
	{
		Node* current = new Node {value, head};
		head = current;
		tail = head->nextNode;
	}
	else
	{
		Node* current = new Node {value, head};
		head = current;
	}

}

template <typename T>
void List<T>::PopIndex(T index)
{
	if(index >= 0 && index < size)
	{
		if(index == 0)
			PopFront();
		else if(index == size - 1)
			PopBack();
		else
		{
			size--;
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

template <typename T>
void List<T>::PopFront()
{
	if(head != nullptr)
	{
		size--;
		Node* current = head;
		head = head->nextNode;
		delete current;
		if(head->nextNode == nullptr)
			tail = nullptr;
	}

}

template <typename T>
void List<T>::Remove(const T& value)
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

			if(current->nextNode == nullptr)
				tail = prev;

			size--;
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

template <typename T>
bool List<T>::Find(const T& value) const
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

template <typename T>
bool List<T>::IsEmpty() const
{
	return size == 0 ? true : false;
}

template <typename T>
size_t List<T>::Size() const
{
	return size;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if(this != &other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& other) noexcept
{

	if(this != &other)
	{
		Clear();

		head = other.head;
		other.head = nullptr;
	}
	return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::Begin()
{
	Iterator iterator(head);
	return iterator;
}

template <typename T>
typename List<T>::Iterator List<T>::End()
{
	Iterator iterator(tail->nextNode);
	return iterator;
}

template <typename T>
List<T>::Iterator::Iterator(Node* node)
	: node(node)
{
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const
{
	return node != other.node;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	node = node->nextNode;
	return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
	Iterator temp(*this);
	node = node->nextNode;
	return temp;
}

template <typename T>
typename T& List<T>::Iterator::operator*()
{
	return node->data;
}
