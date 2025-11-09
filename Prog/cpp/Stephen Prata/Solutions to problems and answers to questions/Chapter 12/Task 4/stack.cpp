#include "stack.h"

Stack::Stack(int n)    
{
    if(n > 1)
        pitems = new Item[n];
    else
        pitems = nullptr;
    top = 0;
    size = n;
}

Stack::Stack(const Stack& other)
{
    pitems = new Item[other.size];
    for(size_t i = 0; i < other.size; i++)
    {
        pitems[i] = other.pitems[i];
    }
    size = other.size;
    top = other.top;
}

Stack::~Stack()
{
    delete[]pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item) 
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false; 
}

Stack& Stack::operator=(const Stack& other)
{
    if(this == &other)
    {
        return *this;
    }
    delete[]pitems;

    pitems = new Item[other.size];
    for(size_t i = 0; i < other.size; i++)
    {
        pitems[i] = other.pitems[i];
    }
    size = other.size;
    top = other.top;
    return *this;
}
