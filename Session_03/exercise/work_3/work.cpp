//  编写一个程序，要求用户以度、分、秒的方式输入一个纬度，然后以度为单位显示该纬度。一度为60分，一分为60秒。
#include <iostream>

const double minutes_per_degree = 60;
const double seconds_per_minutes = 60;

int main()
{
    using namespace std;
    int degree;
    int minute;
    int second;

    cout << "Enter a latitude in degrees, minutes, and seconds:\n"
         << "First, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin >> minute;
    cout << "Finally, enter the seconds of arc: ";
    cin >> second;
    cout << degree << " degrees, " << minute << " minutes, " << second
         << " seconds = "
         << degree + (second / seconds_per_minutes + minute) / minutes_per_degree
         << " degrees\n";
    return 0;
}