#pragma once

template <typename T>
class DoubleList
{
private:
	struct Node
	{
		T value;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
	size_t size;

	void Copy(const DoubleList& ohter);
	void Move(DoubleList&& ohter);

public:

	class Iterator
	{
	private:
		Node* ptr;
	public:
		Iterator(Node* ptr)
			: ptr(ptr)
		{ }
		
		T& operator*() { return ptr->value; }
		T* operator->() { return &ptr->value; }
		Iterator& operator++() { ptr = ptr->next; return *this; }
		Iterator operator++(int) { Iterator temp(*this); ptr = ptr->next; return temp; }
		Iterator& operator--() { ptr = ptr->prev; return *this; }
		Iterator operator--(int) { Iterator temp(*this); ptr = ptr->prev; return temp; }
		bool operator==(const Iterator& other) { return ptr == other.otr; }
		bool operator!=(const Iterator& other) { return ptr != other.ptr; }
		
	};

	Iterator Begin() { return Iterator(head); }
	Iterator End() { return Iterator(nullptr); }

	class ConstIterator
	{
	private:
		Node* ptr;
	public:
		ConstIterator(Node* ptr)
			: ptr(ptr)
		{ }
		 
		const T& operator*() { return ptr->value; }
		const T* operator->() const { return &ptr->value; }
		ConstIterator& operator++() { ptr = ptr->next; return *this; }
		ConstIterator operator++(int) { ConstIterator temp(*this); ptr = ptr->next; return temp; }
		ConstIterator& operator--() { ptr = ptr->prev; return *this; }
		ConstIterator operator--(int) { ConstIterator temp(*this); ptr = ptr->prev; return temp; }
		bool operator==(const ConstIterator& other) const { return ptr == other.otr; }
		bool operator!=(const ConstIterator& other) const { return ptr != other.ptr; }

	};

	ConstIterator CBegin() const { return ConstIterator(head); }
	ConstIterator CEnd() const { return ConstIterator(nullptr); }

	class ReverseIterator
	{
	private:
		Node* ptr;
	public:
		ReverseIterator(Node* ptr)
			: ptr(ptr)
		{ }

		T& operator*() { return ptr->value; }
		T* operator->() { return &ptr->value; }
		ReverseIterator& operator++() { ptr = ptr->prev; return *this; }
		ReverseIterator operator++(int) { ReverseIterator temp(*this); ptr = ptr->prev; return temp; }
		ReverseIterator& operator--() { ptr = ptr->next; return *this; }
		ReverseIterator operator--(int) { ReverseIterator temp(*this); ptr = ptr->next; return temp; }
		bool operator==(const ReverseIterator& other) { return ptr == other.otr; }
		bool operator!=(const ReverseIterator& other) { return ptr != other.ptr; }

	};
	
	ReverseIterator RBegin() { return ReverseIterator(tail); }
	ReverseIterator REnd() { return ReverseIterator(nullptr); }

	class ConstReverseIterator
	{
	private:
		Node* ptr;
	public:
		ConstReverseIterator(Node* ptr)
			: ptr(ptr)
		{ }

		const T& operator*() { return ptr->value; }
		const T* operator->() const { return &ptr->value; }
		ConstReverseIterator& operator++() { ptr = ptr->prev; return *this; }
		ConstReverseIterator operator++(int) { ConstReverseIterator temp(*this); ptr = ptr->prev; return temp; }
		ConstReverseIterator& operator--() { ptr = ptr->next; return *this; }
		ConstReverseIterator operator--(int) { ConstReverseIterator temp(*this); ptr = ptr->next; return temp; }
		bool operator==(const ConstReverseIterator& other) const { return ptr == other.otr; }
		bool operator!=(const ConstReverseIterator& other) const { return ptr != other.ptr; }

	};

	ConstReverseIterator CRBegin() const { return ConstReverseIterator(tail); }
	ConstReverseIterator CREnd() const { return ConstReverseIterator(nullptr); }

	DoubleList();
	DoubleList(const DoubleList& other);
	DoubleList(DoubleList&& other) noexcept;

	DoubleList& operator=(const DoubleList& other);
	DoubleList& operator=(DoubleList&& other) noexcept;

	~DoubleList();

	void PushFront(T value);
	void PushBack(T value);

	void PopFront();
	void PopBack();
	
	T& Front();
	const T& Front() const;
	T& Back();
	const T& Back() const;

	void Remove(const T& value);
	bool Find(T value);

	void Reverse();
	void Clear();

	bool IsEmpty() const;
	size_t Size() const;

	void Swap(DoubleList& other) noexcept;
};

template <typename T>
void DoubleList<T>::Copy(const DoubleList& other)
{
	if(other.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	else
	{
		head = new Node {other.head->value, nullptr, nullptr};

		Node* copyOther = other.head;
		Node* copyhead = head;
		while(copyOther != nullptr)
		{
			copyhead->next = new Node {copyOther->value, nullptr, copyhead};
			copyhead = copyhead->next;
			copyOther = copyOther->next;
		}
		tail = copyhead;
		size = other.size;
	}
}

template <typename T>
void DoubleList<T>::Move(DoubleList<T>&& other)
{
	head = other.head;
	tail = other.tail;
	size = other.size;
	other.head = nullptr;
	other.tail = nullptr;
	other.size = 0;
}

template <typename T>
DoubleList<T>::DoubleList()
	: size(0), head(nullptr), tail(nullptr)
{
}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList<T>& other)
	: size(0), head(nullptr), tail(nullptr)
{
	if(other.size != 0)
	{
		Copy(other);
	}
}

template <typename T>
DoubleList<T>::DoubleList(DoubleList<T>&& other) noexcept
	: size(0), head(nullptr), tail(nullptr)
{
	Move(std::move(other));

}

template <typename T>
DoubleList<T>::~DoubleList()
{
	Clear();
}

template <typename T>
void DoubleList<T>::PushFront(T value)
{
	if(size == 0)
	{
		head = new Node {value, nullptr, nullptr};
		tail = head;
	}
	else
	{
		head = new Node {value, head, nullptr};
		head->next->prev = head;
	}
	size++;
}

template <typename T>
void DoubleList<T>::PushBack(T value)
{
	if(size == 0)
	{
		head = new Node {value, nullptr, nullptr};
		tail = head;
	}
	else
	{
		tail->next = new Node {value, nullptr, tail};
		tail = tail->next;
	}
	size++;
}

template <typename T>
void DoubleList<T>::PopFront()
{
	if(size != 0)
	{
		Node* copy = head;
		head = head->next;
		delete copy;
		size--;
	}
}

template <typename T>
void DoubleList<T>::PopBack()
{
	if(size == 0)
		return;
	else if(size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* copy = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete copy;
	}
	size--;
}

template<typename T>
inline T& DoubleList<T>::Front()
{
	return head->value;
}

template<typename T>
inline const T& DoubleList<T>::Front() const
{
	return head->value;
}

template<typename T>
inline T& DoubleList<T>::Back()
{
	return tail->value;
}

template<typename T>
inline const T& DoubleList<T>::Back() const
{
	return tail->value;
}

template <typename T>
void DoubleList<T>::Clear()
{
	while(head != nullptr)
	{
		Node* copy = head;
		head = head->next;
		delete copy;
	}
	tail = nullptr;
	size = 0;
}

template <typename T>
void DoubleList<T>::Reverse()
{
	tail = head;

	Node* copy = head;
	Node* temp = nullptr;

	while(copy != nullptr)
	{
		temp = copy->prev;
		copy->prev = copy->next;
		copy->next = temp;
		copy = copy->prev;
	}

	if(temp != nullptr)
		head = temp->prev;

}

template <typename T>
void DoubleList<T>::Remove(const T& value)
{
	if(size != 0)
	{
		Node* copy = head;
		Node* prev = nullptr;

		while(copy != nullptr)
		{
			if(copy->value == value)
			{
				Node* temp = copy;

				if(copy == head)
				{
					if(size == 1)
					{
						head = nullptr;
						tail = nullptr;
					}
					else
					{
						head = head->next;
						head->prev = nullptr;
					}
				}
				else if(copy == tail)
				{
					tail = tail->prev;
					tail->next = nullptr;
				}
				else
				{
					copy->prev->next = copy->next;
					copy->next->prev = copy->prev;
				}

				copy = copy->next;
				delete temp;
				size--;
			}
			else
			{
				copy = copy->next;
			}
		}
	}
}

template <typename T>
bool DoubleList<T>::Find(T value)
{
	Node* copy = head;
	while(copy != nullptr)
	{
		if(copy->value == value)
			return true;
		copy = copy->next;
	}
	return false;
}

template <typename T>
bool DoubleList<T>::IsEmpty() const
{
	return size == 0 ? true : false;
}

template <typename T>
size_t DoubleList<T>::Size() const
{
	return size;
}

template<typename T>
inline void DoubleList<T>::Swap(DoubleList& other) noexcept
{
	Node* temp = head;
	head = other.head;
	other.head = temp;

	temp = tail;
	tail = other.tail;
	other.tail = temp;

	std::swap(size, other.size);
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList<T>& other)
{
	if(this != &other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator=(DoubleList<T>&& other) noexcept
{
	if(this != &other)
	{
		Clear();
		Move(std::move(other));
	}
	return *this;
}
