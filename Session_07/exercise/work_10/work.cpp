//  设计一个名为calculate( )的函数，它接受两个double值和一个指向函数的指针，
//  而被指向的函数接受两个double参数，并返回一个double值。
//  calculate( )函数的类型也是double，并返回被指向的函数使用calculate( )的两个double参数计算得到的值。
//  例如，假设add( )函数的定义如下：
//  double add(double x, double y)
//  {
//       return x + y;
//   }
// 则下述代码中的函数调用将导致calculate( )把2.5和10.4传递给add( )函数，
// 并返回add( )的返回值（12.9）：
//  double q = calculate(2.5, 10.4, add);
//  请编写一个程序，它调用上述两个函数和至少另一个与add( )类似的函数。
//  该程序使用循环来让用户成对地输入数字。对于每对数字，
//  程序都使用calculate( )来调用add( )和至少一个其他的函数。
//  如果读者爱冒险，可以尝试创建一个指针数组，其中的指针指向add( )样式的函数，
//  并编写一个循环，使用这些指针连续让calculate( )调用这些函数。
//  提示：下面是声明这种指针数组的方式，其中包含三个指针：
//  double (*pf[3])(double, double);
//  可以采用数组初始化语法，并将函数名作为地址来初始化这样的数组。
#include <iostream>
using namespace std;

double add(double x, double y);
double sub(double x, double y);
double calculate(double x, double y, double (**pf)(double, double), int n);

int main()
{
    double (*pf[2])(double, double) = {&add, &sub};
    cout << "Enter x: ";
    double x;
    cin >> x;
    cout << "Enter y: ";
    double y;
    cin >> y;
    for (int i = 0; i < 2; i++)
    {
        calculate(x, y, pf, i);
    }
}

double calculate(double x, double y, double (**pf)(double, double), int n)
{
    cout << "Result #" << n + 1 << ": " << pf[n](x, y) << endl;
}

double add(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}