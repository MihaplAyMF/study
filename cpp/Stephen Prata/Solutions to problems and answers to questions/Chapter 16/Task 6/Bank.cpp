#include <iostream>
#include <queue>

using namespace std;

const int MIN_PER_HR = 60;

class Customer
{
private:
    long arrive;       
    int processtime;   
public:
    Customer() : arrive(0), processtime(0) {}
    void set(long when)
    {
        processtime = std::rand() % 3 + 1;
        arrive = when;
    }
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

bool newcustomer(double x); 

int main()
{
   srand(static_cast<unsigned int>(time(nullptr)));    

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    
    int qs;
    cin >> qs;
    
    queue<Customer> line;
   
    cout << "Enter the number of simulation hours: ";
    int hours;   
    cin >> hours;

    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;       
    cin >> perhour;
    double min_per_cust;    
    min_per_cust = MIN_PER_HR / perhour;

    Customer temp;
    long turnaways = 0;     
    long customers = 0;     
    long served = 0;        
    long sum_line = 0;     
    int wait_time = 0;     
    long line_wait = 0;   

    for(int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if(newcustomer(min_per_cust)) 
        {
            if(line.size() <= qs)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    
                line.push(temp); 
            }
        }
        if(wait_time <= 0 && !line.empty())
        {
            line.push(temp);    
            wait_time = temp.ptime(); 
            line_wait += cycle - temp.when();
            served++;
        }
        if(wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

    if(customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
            << (double)line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
