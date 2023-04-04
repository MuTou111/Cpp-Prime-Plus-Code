//  编写通常接受一个参数（字符串的地址），并打印该字符串的函数。
//  然而，如果提供了第二个参数（int类型），且该参数不为0，
//  则该函数打印字符串的次数将为该函数被调用的次数
//  （注意，字符串的打印次数不等于第二个参数的值，而等于函数被调用的次数）。
//  是的，这是一个非常可笑的函数，但它让您能够使用本章介绍的一些技术。
//  在一个简单的程序中使用该函数，以演示该函数是如何工作的。
#include <iostream>

using namespace std;

void Show (string str, int flag = 0);

int main()
{
    string str = "Hello World";
    Show(str);
    Show(str, 1);
    return 0;
}

void Show(string str, int flag)
{
    static int count = 1;
    if(flag == 0)
        cout << str << endl;
    else
        for(int i = 0; i < count; i++)
            cout << str << endl;
    
    count++;
}