#include <iostream>
#include "classic.h"

using namespace std;

void Bravo(const Cd& disk);

int main()
{
    Cd cOne("Beatles", "Capitol", 14, 35.5);
    Classic cTwo = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

    Cd* pcd = &cOne;

    cout << "Using object directly: ";
    cOne.Report();
    cTwo.Report();

    cout << endl << "Using type cd* pointer to opjects: ";
    pcd->Report();
    pcd = &cTwo;
    pcd->Report();

    cout << endl << "Calling a function with a Cd reference argument: ";
    Bravo(cOne);
    Bravo(cTwo);

    cout << endl << "Testing assigment: ";
    Classic copy;
    copy = cTwo;
    copy.Report();

    return 0;
}

void Bravo(const Cd& disk)
{
    disk.Report();
}