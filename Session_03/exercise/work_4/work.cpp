//  编写一个程序，要求用户以整数方式输入秒数（使用long或longlong变量存储）
//  然后以天、小时、分钟和秒的方式显示时间。
#include <iostream>

const int second_per_minute = 60;
const int minute_per_hour = 60;
const int hour_per_day = 24;

int main()
{
    using namespace std;
    long long time;
    int time_day, time_hour, time_minute, time_second;
    cout << "Enter the number of seconds = ";
    cin >> time;
    cout << time << " seconds = ";

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            time_second = time % second_per_minute;
            time /= second_per_minute;
            break;
        case 1:
            time_minute = time % minute_per_hour;
            time /= minute_per_hour;
            break;
        case 2:
            time_hour = time % hour_per_day;
            time /= hour_per_day;
            break;
        default:
            break;
        }
    }
    time_day = time;

    cout << time_day << " days, "
         << time_hour << " hours, "
         << time_minute << " minutes, "
         << time_second << " seconds\n";

    return 0;
}