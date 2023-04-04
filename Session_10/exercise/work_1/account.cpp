#include <iostream>
#include "account.h"

Account::Account(const string &name, const string &acc, double balance)
{
    this->name = name;
    this->acc = acc;
    this->balance = balance;
}

Account::~Account()
{
}

void Account::show()
{
    using namespace std;
    cout << "Name: " << this->name << endl;
    cout << "Account: " << this->acc << endl;
    cout << "Balance: " << this->balance << endl;
}

void Account::credit(double money)
{
    if (money < 0)
    {
        cout << "Can't be negative!\n";
    }
    else
    {
        this->balance += money;
    }
}

void Account::withdraw(double money)
{
    if (money < 0)
    {
        cout << "Can't be negative!\n";
    }
    else if (money > this->balance)
    {
        cout << "Can't more than balance!\n";
    }
    else
    {
        this->balance -= money;
    }
}