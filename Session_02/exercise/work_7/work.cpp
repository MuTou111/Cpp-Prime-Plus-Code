//  编写一个程序，要求用户输入小时数和分钟数。
#include <iostream>

void fun(const int &h, const int &m)
{
    using namespace std;
    cout << "Time: " << h << ":" << m << endl;
}

int main()
{
    using namespace std;
    int h, m;
    cout << "Enter the number of hours: ";
    cin >> h;
    cout << "Enter the number of minutes: ";
    cin >> m;
    fun(h, m);
    return 0;
}