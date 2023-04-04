//  编写一个程序，让用户输入三次40码跑的成绩（如果愿意，也可以是40米跑）
//  并显示次数和平均成绩。
//  请使用array对象来存储数据
#include <iostream>
#include <array>

int main()
{
    using namespace std;
    array<double, 3> grade;
    int count = 0;
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter #" << i+1 << " time grade: ";
        if (cin >> grade[i])
        {
            count++;
            sum += grade[i];
        }
        else
        {
            cout << "\nError input, input is aborted.\n\n";
            break;
        }
    }

    cout << "Times: " << count << endl;
    cout << "Average grade: " << sum / count << endl;

    return 0;
}