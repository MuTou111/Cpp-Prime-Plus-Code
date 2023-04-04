//  编写一个函数，它接受一个指向string对象的引用作为参数，
//  并将该string对象的内容转换为大写，为此可使用表6.4描述的函数toupper( )。
//  然后编写一个程序，它通过使用一个循环让您能够用不同的输入来测试这个函数，
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void change(string &);

int main()
{
    string str = {};
    while (1)
    {
        cout << "Enter the stirng(Empty to quit): ";
        getline(cin, str);
        if (str == "")
            break;
        change(str);
        cout << "Changed string: " << str << endl;
    }
    cout << "Done\n";
}

void change(string &str)
{
    char ch;
    for (int i = 0; i < str.length(); i++)
    {
        ch = str[i];
        if (islower(ch))
        {
            ch = toupper(ch);
            str[i] = ch;
        }
    }
}
