#include <string>
using namespace std;
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account
{
private:
    string name;
    string acc;
    double balance;

public:
    Account(const string &, const string &, double = 0);
    ~Account();
    void show();
    void credit(double cash);
    void withdraw(double cash);
};

#endif