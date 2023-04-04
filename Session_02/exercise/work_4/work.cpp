//  编写一个程序，让用户输入其年龄，然后显示该年龄包含多少个月
#include <iostream>

using namespace std;

int main()
{
    short age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "You have been " << age * 12 << " months old.";
    return 0;
}