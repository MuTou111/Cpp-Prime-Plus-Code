//  修改程序清单9.9：用string对象代替字符数组。这样，
//  该程序将不再需要检查输入的字符串是否过长，同时可以将输入字符串同字符串“”进行比较，
//  以判断是否为空行。
#include <iostream>
#include <string>
//  constants
const int ArSize = 10;

//  funciton prototype
void strcount(const std::string str);

int main()
{
    using namespace std;
    string input;

    cout << "Enter a line:\n";
    getline(cin, input);
    while (input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const std::string str)
{
    using namespace std;
    static int total = 0; //  static local variable
    int count = 0;        //  automatic local variable

    cout << "\"" << str << "\" contains ";
    while (str[count]) //  go to end of string
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}