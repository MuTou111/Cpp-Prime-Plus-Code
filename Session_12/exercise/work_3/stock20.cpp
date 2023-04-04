#include "stock20.h"
#include <cstring>

//  constructors
Stock::Stock() //  default constructor
{
    company = new char[strlen("No Name") + 1];
    strcpy(company, "No Name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char *ch, long n, double pr)
{
    company = new char[strlen(ch) + 1];
    strcpy(company, ch);

    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

//  class destructor
Stock::~Stock() //  quiet class destructor
{
    delete[] company;
}

//  other methods
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

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    //  set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company
         << " Shares: " << shares << '\n';
    cout << "\t Share Price: $" << share_val;
    //  set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';

    //  restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock &Stock::topval(const Stock &s) const
{
    if (s.share_val > this->share_val)
        return s;
    else
        return *this;
}

std::ostream &operator<<(std::ostream &os, const Stock &s)
{
    using std::ios_base;
    //  set format to #.###
    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os << "Company: " << s.company
       << " Shares: " << s.shares << '\n';
    os << "\t Share Price: $" << s.share_val;
    //  set format to #.##
    os.precision(2);
    os << " Total Worth: $" << s.total_val << '\n';

    //  restore original format
    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
    return os;
}