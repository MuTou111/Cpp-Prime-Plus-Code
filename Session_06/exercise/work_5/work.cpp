//  在Neutronia王国，货币单位是tvarp，收入所得稅的计算方式如下：
//  5000tvarps：不收税
//  5001～1500tvarps：10%
//  15001～35000tvarps：15%
//  35000tvarps 以上：20%
#include <iostream>

using namespace std;

int main()
{
    double money = 0;
    cout << "Enter your income: ";
    while (cin >> money)
    {
        double tax = 0;
        if (money > 35000)
        {
            tax += (money - 35000) * 0.2;
            money = 35000;
        }
        if (money > 15000)
        {
            tax += (money - 15000) * 0.15;
            money = 15000;
        }
        if (money > 5000)
        {
            tax += (money - 5000) * 0.1;
            money = 5000;
        }
        cout << "Your tax is " << tax << endl;
        cout << "Enter your income: ";
    }
    cout << "Bye！\n";
    return 0;
}