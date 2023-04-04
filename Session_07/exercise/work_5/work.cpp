//  定义一个递归函数，接受一个整数参数，并返回该参数的阶乘。
//  前面讲过，3的阶乘写作3!，等于3*2!，依此类推；而0!被定义为1。
//  通用的计算公式是，如果n大于零，则n!=n*（n−1）!。
//  在程序中对该函数进行测试，程序使用循环让用户输入不同的值，程序将报告这些值的阶乘。
#include <iostream>

using namespace std;

long long calculator(long long);

int main()
{
    int n = 0;
    cout << "Enter the number(q to quit): ";
    while (cin >> n)
    {
        cout << n << "! = " << calculator(n) << endl;
        cout << "Enter the number(q to quit): ";
    }
    cout << "Bye~\n";

    return 0;
}

long long calculator(long long n)
{
    if (n <= 0)
        return 1;
    else
        return n * calculator(n - 1);
}