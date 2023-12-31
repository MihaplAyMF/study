#include <iostream>
#include "stock20.h"

using namespace std;

//Stock::Stock()       
//    : shares(0), share_val(0.0), total_val(0.0)
//{}

Stock::Stock(const char* co, long n, double pr)
{

    company = new char[strlen(co) + 1];
    strcpy(company, co);
    if (n < 0)
    {
        cout << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{

}

void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

const Stock& Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this; 
}

ostream& operator<<(ostream& os, const Stock& other)
{
    ios_base::fmtflags orig =
        os.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = os.precision(3);

    os << "Company: " << other.company << "\n"
       << "Shares: " << other.shares << '\n'
       << "Share Price: $" << other.share_val;
    os.precision(2);
    os << "  Total Worth: $" << other.total_val << '\n';

    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
    return os;
}
