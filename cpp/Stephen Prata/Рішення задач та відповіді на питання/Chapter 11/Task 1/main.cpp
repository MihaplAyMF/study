#include <iostream>
#include <fstream>
#include <cstdlib>      
#include <ctime>        
#include "Vector.h"

using namespace std;
using VECTOR::Vector;

int main()
{
    srand(static_cast<int>(time(nullptr)));
    
    ofstream outputFile("myfile.txt");
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    outputFile << "TEST" << endl;
    
    cout << "Enter target distance (q to quit): ";
    while(cin >> target)
    {
        outputFile << "Target Distance: " << target;
        cout << "Enter step length: ";
        if(!(cin >> dstep))
            break;
        
        outputFile << ", Step Size: " << dstep << endl;

        outputFile << steps << ": (x, y) = (" << step.GetX()
            << ", " << step.Gety() << ")";

        while(result.GetMag() < target)
        {
            direction = rand() % 360;
            step.Reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            outputFile << steps << ": (x, y) = (" << step.GetX()
                << ", " << step.Gety() << ")" << endl;
            cout << steps << endl;
        }

        outputFile << "After " << steps << " steps, the subject "
            "has the following location:\n";
        result.RectMode();
        outputFile << result << endl;
        result.PolarMode();
        outputFile << " or\n" << result << endl;
        outputFile << "Average outward distance per step = "
            << result.GetMag() / steps << endl;
        steps = 0;
        result.Reset(0.0, 0.0);
        outputFile << "Enter target distance (q to quit): ";
        break;
    }
    cout << "Bye!\n";
 
    return 0;
}
