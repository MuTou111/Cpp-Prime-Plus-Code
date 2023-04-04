//  编写一个要求用户输入两个整数的程序。
//  该程序计算并输出这两个整数之间（包括这两个整数）所有整数的和。
#include <iostream>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    int min;
    int max;
    cout << "Enter the min: ";
    cin >> min;
    cout << "Enter the max: ";
    cin >> max;

    int sum = 0;
    for (int i = min; i <= max; i++)
    {
        sum += i;
    }

    cout << "The sum from " << min << " to " << max
         << " is " << sum << endl;

    return 0;
}