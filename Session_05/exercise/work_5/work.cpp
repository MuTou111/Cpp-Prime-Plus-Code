//  假设要销售《C++ For Fools》一书。请编写一个程序，输入全年中每个月的销售量（图书数量）
//  程序通过循环，使用初始化月份字符串的char*数组（或string数组）逐月进行提示
//  并将输入的数据存储在一个int数组中。然后计算数组中各元素的总数，并报告这一年的销售情况。
#include <iostream>
const char *months[12] = {
    "Jan", "Feb", "Mar",
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"};
int main()
{
    using namespace std;
    int sell[12] = {};
    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        cout << "Enter the sales of " << months[i] << ": ";
        if (!(cin >> sell[i]))
        {
            cout << "\nError Input!\nProcess is aborted!\n";
            return 0;
        }
        sum += sell[i];
    }
    cout << "The sales of whole year is " << sum << endl;

    return 0;
}