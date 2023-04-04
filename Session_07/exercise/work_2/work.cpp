//  编写一个程序，要求用户输入最多10个高尔夫成绩，并将其存储在一个数组中。
//  程序允许用户提早结束输入，并在一行上显示所有成绩，然后报告平均成绩。
//  请使用3个数组处理函数来分别进行输入、显示和计算平均成绩。
#include <iostream>

using namespace std;

int input(double *grade);
void show(double *grade, int len);
void average(double *grade, int len);

int main()
{
    double grade[10] = {};
    int count = 0;

    count = input(grade);
    show(grade, count);
    average(grade, count);

    return 0;
}

int input(double *grade)
{
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter #" << i + 1 << " grade(-1 to quit): ";
        if (!(cin >> grade[i]))
        {
            cout << "Bad Input!!!\ninput again:\n";
            i--;
            cin.clear();
            cin.ignore();
            continue;
        }
        else if (grade[i] == -1)
        {
            cout << "End input.\n";
            break;
        }
        else
            count++;
    }
    return count;
}

void show(double *grade, int len)
{
    for (int i = 0; i < len; i++)
        cout << "#" << i + 1 << ": " << grade[i] << "\t";
    cout << endl;
}

void average(double *grade, int len)
{
    if (len == 0)
        return;
    double sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += grade[i];
    }
    cout << "Average: " << sum / len << endl;
}