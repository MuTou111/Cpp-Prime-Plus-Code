//  编写一个程序，要求用户输入全球当前的人口和美国当前的人口（或其他国家的人口）。
//  将这些信息存储在longlong变量中，并让程序显示美国（或其他国家）的人口占全球人口的百分比。
#include <iostream>

using namespace std;

int main()
{
    long long global_population;
    long long national_population;

    cout << "Enter the world's population: ";
    cin >> global_population;
    cout << "Enter the populattion of your nation: ";
    cin >> national_population;
    cout << "The population of your nation is "
         << double(national_population) / global_population * 100
         << "% of the world population.\n";

    return 0;
}