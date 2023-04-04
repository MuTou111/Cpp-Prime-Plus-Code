//  编写一个程序，读取键盘输入，直到遇到@符号为止，并回显输入（数字除外）
//  同时将大写字符转换为小写，将小写字符转换为大写（别忘了cctype函数系列）
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char ch[100] = {};
    cout << "Enter the string(enter @ to quit): \n";
    for(int i = 0; i < 100; i++)
    {
        ch[i] = cin.get();
        if(ch[i] >= '0' && ch[i] <= '9')
            i--;
        else if(islower(ch[i]))
            ch[i] = toupper(ch[i]);
        else if(isupper(ch[i]))
            ch[i] = tolower(ch[i]);
        else if(ch[i] == '@')
        {
            ch[i] = '\0';
            break;
        }
    }
    cout << ch << endl;;
    return 0;
}