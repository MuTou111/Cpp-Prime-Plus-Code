#include "account.h"

int main()
{
    string name = "A";
    string acc = "A_1";
    double balance = 1000;
    Account account = Account(name, acc, balance);
    account.show();
    account.credit(150);
    account.show();
    account.withdraw(150);
    account.show();

    return 0;
}