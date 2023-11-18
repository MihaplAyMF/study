#pragma once
#include "doubleListTemplate.h"

template <typename T>
class Queue
{
private:
	DoubleList<T> list;
public:
	Queue() = default;
	Queue(const Queue& other) = default;
	Queue(Queue&& other) noexcept = default;

	~Queue() = default;

	Queue& operator=(const Queue& other) = default;
	Queue& operator=(Queue&& other) = default;

	void Pop();
	void Push(const T& value);
	size_t Size() const;
	void Swap(Queue& other) noexcept;
	bool IsEmpty() const;

	T& Front();
	const T& Front() const;

	T& Back();
	const T& Back() const;
};

template<typename T>
inline void Queue<T>::Pop()
{
	list.PopFront();
}

template<typename T>
inline void Queue<T>::Push(const T& value)
{
	list.PushBack(value);
}

template<typename T>
inline size_t Queue<T>::Size() const
{
	return list.Size();
}

template<typename T>
inline void Queue<T>::Swap(Queue& other) noexcept
{
	list.Swap(other.list);
}

template<typename T>
inline bool Queue<T>::IsEmpty() const
{
	return list.IsEmpty();
}

template<typename T>
inline T& Queue<T>::Front()
{
	return list.Front();
}

template<typename T>
inline const T& Queue<T>::Front() const
{
	return list.Front();
}

template<typename T>
inline T& Queue<T>::Back()
{
	return list.Back();
}

template<typename T>
inline const T& Queue<T>::Back() const
{
	return list.Back();
}
