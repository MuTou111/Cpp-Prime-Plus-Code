//  许多州的彩票发行机构都使用如程序清单7.4所示的简单彩票玩法的变体。
//  在这些玩法中，玩家从一组被称为域号码（field number）的号码中选择几个。
//  例如，可以从域号码1～47中选择5个号码；
//  还可以从第二个区间（如1～27）选择一个号码（称为特选号码）。
//  要赢得头奖，必须正确猜中所有的号码。
//  中头奖的几率是选中所有域号码的几率与选中特选号码几率的乘积。
//  例如，在这个例子中，中头奖的几率是从47个号码中正确选取5个号码的几率与从27个号码中正确选择1个号码的几率的乘积。
//  请修改程序清单7.4，以计算中得这种彩票头奖的几率。
#include <iostream>
//  NOTE: some implementations require double instead of long double
long double probability(unsigned numbers, unsigned picks);
int main()
{
    using namespace std;
    double total, choices, sp_total, sp_choices;
    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed:\n";
    while ((cin >> total >> choices >> sp_total >> sp_choices) && choices <= total && sp_choices <= sp_total)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices) * probability(sp_total, sp_choices); //  compute the odds
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";
    return 0;
}

//  the following function calculate the probability of picking picks
//  numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0; //  here come some local variables
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}