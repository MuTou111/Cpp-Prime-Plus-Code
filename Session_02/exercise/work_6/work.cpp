//  编写一个程序，其main（）调用一个用户定义的函数（以光年值为参数，并返回对应天文单位的值）
#include <iostream>

double converter(const double &ly)
{
    return ly * 63240;
}

int main()
{
    using namespace std;
    double ly;
    cout << "Enter the number of light years: ";
    cin >> ly;
    cout << ly << " light years = " << converter(ly) << " astronomical units.\n";
    return 0;
}