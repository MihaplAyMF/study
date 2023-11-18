#include <iostream>
#include "classic.h"

using namespace std;

class A // Corporation
{
public:
    A() { }
    A(const A& other)
    {
        cout << "Constructor copy A";
    }
    ~A() { }

    virtual void head()
    {
        cout << "Head A" << endl;
    }

    virtual void Print()
    {
        cout << "Print A";
    }
};

class B : public A // PublicCorporation
{
public:
    B() { }
    B(const B& other)
    {
        cout << "Constructor copy B";
    }
    ~B() { }

    void head()
    {
        cout << "Head B" << endl;
    }

    void Print() override
    {
        cout << "Print B" << endl;
    }
};

void Pr(A a)
{
    a.Print();
}

int main()
{
    Classic test("Test1", "Test2", "Test3", 5, 12.3);

    test.Report();

    return 0;
}
