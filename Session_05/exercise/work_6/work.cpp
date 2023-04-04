//  完成编程练习5，但这一次使用一个二维数组来存储输入一个3年中每个月的销售量。
//  程序报告每年销售量和三年的总销售量
#include <iostream>
const char *months[12] = {
    "Jan", "Feb", "Mar",
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"};
int main()
{
    using namespace std;
    int sell[3][12] = {};
    int sum_year[3] = {};
    int sum = 0;
    for (int k = 0; k < 3; k++)
        for (int i = 0; i < 12; i++)
        {
            cout << "Enter the sales of " << months[i] << "/# " << k + 1 << " year: ";
            if (!(cin >> sell[k][i]))
            {
                cout << "\nError Input!\nProcess is aborted!\n";
                return 0;
            }
            sum_year[k] += sell[k][i];
            sum += sell[k][i];
        }
    for (int i = 0; i < 3; i++)
    {
        cout << "The sales of #" << i + 1 << " year is " << sum_year[i] << endl;
    }
    cout << "The sales of all three years is " << sum << endl;

    return 0;
}
