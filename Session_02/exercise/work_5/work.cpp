//  编写一个程序，其中的main（）调用一个用户定义的函数（以摄氏度值为参数，并返回相应的华氏温度值）。
#include <iostream>

using namespace std;

double converter(double &temp)
{
    return 1.8 * temp + 32.0;
}

int main()
{
    double temp;
    cout << "Please enter a Celsius value: ";
    cin >> temp;
    cout << temp << " degrees Celsius is " << converter(temp) << " degrees Fahrenheit.\n";
    return 0;
}