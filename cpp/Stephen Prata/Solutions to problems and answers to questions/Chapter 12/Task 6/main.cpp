#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "queue.h"

using namespace std;

const int MIN_PER_HR = 60;

bool newcustomer(double x); 

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));    

    int qs = 2504; // кількість людий в чергі
    Queue lineOne(qs/2);
    Queue lineTwo(qs/2);
    int hours = 100; // кілкьсть годин моделювання
    long cyclelimit = MIN_PER_HR * hours;  // кількість циклів роботи пргрми
    double perhour = 18;   // кількість людей за годину
    double min_per_cust;   // середній час між появленнями клієнтів
    min_per_cust = MIN_PER_HR / perhour;

    Item temp; // дані про клієнта         
    long turnaways1 = 0;     
    long customers1 = 0;     
    long served1 = 0;        
    long sum_line1 = 0;      
    int wait_time1 = 0;      
    long line_wait1 = 0;     

    long turnaways2 = 0;
    long customers2 = 0;
    long served2 = 0;
    long sum_line2 = 0;
    int wait_time2 = 0;
    long line_wait2 = 0;

    for(int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if(newcustomer(min_per_cust)) 
        {
            if(lineOne.queuecount() >= lineTwo.queuecount())
            {
                if(lineOne.isfull())
                    turnaways1++;
                else
                {
                    customers1++;
                    temp.set(cycle);    
                    lineOne.enqueue(temp); 
                }
            }
            else
            {
                if(lineTwo.isfull())
                    turnaways2++;
                else
                {
                    customers2++;
                    temp.set(cycle);
                    lineTwo.enqueue(temp);
                }
            }
        }

        if(wait_time1 <= 0 && !lineOne.isempty())
        {
            lineOne.dequeue(temp);      
            wait_time1 = temp.ptime(); 
            line_wait1 += cycle - temp.when();
            served1++;
        }
        
        if(wait_time2 <= 0 && !lineTwo.isempty())
        {
            lineTwo.dequeue(temp);
            wait_time2 = temp.ptime();
            line_wait2 += cycle - temp.when();
            served2++;
        }

        if(wait_time1 > 0)
            wait_time1--;

        if(wait_time2 > 0)
            wait_time2--;

        sum_line1 += lineOne.queuecount();
        sum_line2 += lineTwo.queuecount();
    }

    if(customers1 + customers2 > 0)
    {
        cout << "customers accepted: " << customers1 + customers2 << endl;
        cout << "  customers served: " << served1 + served2 << endl;
        cout << "         turnaways: " << turnaways1 + turnaways2 << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)(sum_line1 + sum_line2) / cyclelimit << endl;
        cout << " average wait time: "
            << (double)(line_wait1 + line_wait2) / (served1 + served2) << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (rand() * x / RAND_MAX < 1);
}
