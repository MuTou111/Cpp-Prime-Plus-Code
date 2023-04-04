//  编写一个使用嵌套循环的程序，要求用户输入一个值，指出要显示多少行。
//  然后，程序将显示相应行数的星号。
#include <iostream>

using namespace std;

int main()
{
    int row = 0;
    cout << "Enter number of rows: ";
    cin >> row;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            if (j <= row - i)
                cout << ".";
            else
                cout << "*";
        }
        cout << endl;
    }

    return 0;
}