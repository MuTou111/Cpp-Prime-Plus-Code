//  编写一个要求用户输入数字的程序。每次输入后，程序都将报告到目前为止，所有输入的累计和。
//  当用户输入0时，程序结束。
#include <iostream>

int main()
{
    using std::cin;
    using std::cout;

    int num, sum = 0;
    while (1)
    {
        cout << "Enter the number(0 to quit): ";
        cin >> num;
        if (num == 0)
        {
            cout << "Bye~\n";
            break;
        }
        sum += num;
        cout << "The sum of entered numbers: " << sum << '\n';
    }

    return 0;
}