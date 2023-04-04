//  编写一个C++程序，如下述输出示例所示的那样请求并显示信息：
//  What is your first name? Betty Sue
//  What is your last name? Yewe
//  What letter grade do you deserve? B
//  What is your age? 22
//  Name: Yewe, Betty Sue
//  Grade: C
//  Age: 22
//  注意，该程序应该接受的名字包含多个单词，另外，程序将向下调整成绩，即向上调整一个字母。
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string f_name, l_name;
    char grade;
    unsigned short age;

    cout << "What is your first name? ";
    getline(cin, f_name);
    cout << "What is your last name? ";
    getline(cin, l_name);
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << l_name << ", " << f_name << endl;
    cout << "Grade: " << ++grade << endl;
    cout << "Age: " << age << endl;

    return 0;
}