#include <iostream>
#include <cctype>  
#include "stack.h"

int main()
{
    
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);


    std::cout << s1.isfull() << std::endl;
    Stack s2(-1);
    s2.push(2);
    std::cout << s2.isfull() << std::endl;

    unsigned long x = 5;
    s1.pop(x);
    std::cout << s1.isfull() << std::endl;

    Stack s3 = s1;
    return 0;
}
