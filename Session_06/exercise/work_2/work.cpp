//  编写一个程序，最多将10个donation值读入到一个double数组中（如果你愿意，也可使用array）
//  程序遇到非数字输入时将结束输入，并报告这些数字的平均值以及数组中有多少个数字大于平均值
#include <iostream>

using namespace std;

int main()
{
    double donation[10] = {};
    double sum = 0;
    double average = 0;
    int count = 0;
    int num_count = 0;

    cout << "Enter 10 donation value:\n";
    while (count < 10)
    {
        if (!(cin >> donation[count]))
        {
            cout << "Error Input! Process will quit!\n";
            break;
        }
        sum += donation[count];
        count++;
    }
    average = sum / count;
    for (int i = 0; i < count; i++)
        if (donation[i] > average)
            num_count++;

    cout << "Average: " << average << endl;
    cout << num_count << " numbers bigger than average.\n";

    return 0;
}