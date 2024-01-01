#include <iostream>
#include <cstdlib>   
#include <ctime>        
#include "vector.h"

using namespace std;
using VECTOR::Vector;

int main()
{
    srand(static_cast<int>(time(nullptr)));    

    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    int min, max {}, attempts;
    double average {};

    cout << "Enter target distance (q to quit): ";
    while(cin >> target)
    {
        cout << "Enter step length: ";
        if(!(cin >> dstep))
            break;

        cout << "Enter the number of attempts: ";
        if(!(cin >> attempts))
            break;
        for(int i = 0; i < attempts; i++)
        {
            steps = 0;
            result.Reset(0, 0);
            while(result.GetMag() < target)
            {   
                direction = rand() % 360;
                step.Reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
                //cout << step.GetX() << ", " << step.GetY() << endl;
            }
            if(i == 0)
                min = max = average = steps;
            if(steps < min)
                min = steps;
            if(steps > max)
                max = steps;
            average += steps;
            cout << "min: " << min << ", max: " << max << ", average: " << average / (i + 1) << endl;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;
        result.PolarMode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.GetMag() / steps << endl;
        steps = 0;
        result.Reset(0.0, 0.0, Vector::RECT);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";

    return 0;
}
