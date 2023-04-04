//  Daphne以10%的单利投资了100美元。
//  也就是说，每一年的利润都是投资额的10%
//  而Cleo以5%的复利投资了100美元。
//  也就是说，利息是当前存款的5%
//  请编写一个程序，计算多少年后，Cleo的投资价值才能超过Daphne的投资价值
//  并显示此时两个人的投资价值
#include <iostream>

int main()
{
    using namespace std;
    double D_worth = 100, C_worth = 100;
    int year = 0;
    while (C_worth <= D_worth)
    {
        D_worth += 100 * 0.1;
        C_worth += C_worth * 0.05;
        year++;
    }

    cout << "After " << year << " years\n";
    cout << "Daphne's worth: " << D_worth << endl;
    cout << "Cleo's worth: " << C_worth << endl;

    return 0;
}