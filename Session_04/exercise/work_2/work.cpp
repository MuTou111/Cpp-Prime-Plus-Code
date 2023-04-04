//  修改程序清单4.4，使用C++ String类而不是char数组。
#include <iostream>
#include <string>
int main()
{
    using namespace std;
    const int ArSize = 20;
    string name, dessert;
    // char name[ArSize];
    // char dessert[ArSize];

    cout << "Enter your name:\n";
    // cin.getline(name, ArSize);          //reads through newline
    getline(cin, name);                          // reads through newline
    cout << "Enter your favorite dessert:\n";
    // cin.getline(dessert, ArSize);
    getline(cin, dessert);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}