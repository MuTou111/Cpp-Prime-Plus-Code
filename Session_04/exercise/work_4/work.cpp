//  编写一个程序，它要求用户首先输入其名，再输入其姓；
//  然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。
//  请使用string对象和头文件string中的函数。
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string l_name;
    string f_name;
    cout << "Enter your first name: ";
    getline(cin, f_name);
    cout << "Enter your last name: ";
    getline(cin, l_name);

    string name = l_name + ", " + f_name;
    cout << "Here's the information in a single string: "
         << name << endl;

    return 0;
}