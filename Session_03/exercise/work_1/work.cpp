//  编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），然后将身高转换为英尺和英寸。
#include <iostream>
#include <cmath>

int main()
{
    const int change = 12;
    double height;
    using namespace std;

    cout << "Enter your height: ______\b\b\b\b\b\b";
    cin >> height;
    cout << "Your height: " << int(height) / change
         << " feet, " << fmod(height, change)
         << " inches\n";
    return 0;
}