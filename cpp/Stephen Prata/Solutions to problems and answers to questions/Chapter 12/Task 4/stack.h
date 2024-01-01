#pragma once

typedef unsigned long Item;

class Stack
{
private:
    Item* pitems;
    int size;
    int top;     
public:
    Stack(int n = 10);
    Stack(const Stack& other);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item); 
    Stack& operator=(const Stack& other);
};
