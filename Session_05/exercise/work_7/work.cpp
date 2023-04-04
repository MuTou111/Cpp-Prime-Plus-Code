//  设计一个名为car的结构，用它存储下述有关汽车的信息：
//  生产商（存储在字符数组或string对象中的字符串）
//  生产年份（整数）
//  编写一个程序，向用户询问有多少辆汽车。
//  随后使用new来创建一个由相应数量的car结构组成的动态数组。
//  接下来，程序提示用户输入车辆信息。
#include <iostream>
#include <string>
using namespace std;
struct Car
{
    string company;
    int year;
};

int main()
{
    int num = 0;
    Car *car = NULL;

    cout << "How many cars do you wish to catalog? ";
    (cin >> num).get();
    car = new Car[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Car #" << i + 1 << ":\n"
             << "Please enter the make: ";
        getline(cin, car[i].company);
        cout << "Please enter the year made: ";
        (cin >> car[i].year).get();
    }

    cout << "Here is your collection:\n";
    for (int i = 0; i < num; i++)
        cout << car[i].year << " " << car[i].company << endl;

    return 0;
}