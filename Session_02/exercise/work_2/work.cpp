//  编写一个C++程序，它要求用户输入一个以long为单位的距离，然后将它转换为码（一long等于220码）
#include <iostream>

using namespace std;

int main()
{
    int distance;
    cout << "Enter a distance with long: ";
    cin >> distance;
    cout << "distance: " << distance << " long or " << distance * 220 << " yard.";
}