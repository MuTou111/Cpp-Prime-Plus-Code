//  编写一个程序，它要求用户首先输入其名，然后输入其姓；
//  然后程序使用一个逗号和空格将姓和名组合起来
//  并存储和显示结果。使用char数组和头文件cstring中的函数。
#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    char f_name[20], l_name[20];
    cout << "Enter your firstname: ";
    cin.getline(f_name, 20);
    cout << "Enter your lastname: ";
    cin.getline(l_name, 20);

    char name[40] = {};
    strcat(name, l_name);
    strcat(name, ", ");
    strcat(name, f_name);

    cout << "Here's the information in a single string: " << name << endl;

    return 0;
}