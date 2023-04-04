//  编写一个程序，不断要求用户输入两个数，直到其中的一个为0。
//  对于每两个数，程序将使用一个函数来计算它们的调和平均数，并将结果返回给main( )，
//  而后者将报告结果。调和平均数指的是倒数平均值的倒数，计算公式如下：
//  调和平均数=2.0 * x * y / (x + y)
#include <iostream>

using namespace std;

double calculator(double x, double y);

int main()
{
    double x = 0, y = 0;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    while (x && y)
    {
        cout << "Result: " << calculator(x, y) << endl;
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }
    cout << "Bye~\n";

    return 0;
}

double calculator(double x, double y)
{
    return 2.0 * x * y / (x + y);
}