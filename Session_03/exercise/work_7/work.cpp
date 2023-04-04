//  编写一个程序，要求用户按每百公里油耗输入，然后将其转换为每加仑多少英里
#include <iostream>

int main()
{
    using namespace std;
    double fuel_consumption;
    cout << "Enter your fuel_comsumption_per_100km(L) : ";
    cin >> fuel_consumption;
    cout << "Fuel_consumption: "
         << 62.14 / (fuel_consumption / 3.785)
         << "mpg\n";

    return 0;
}