//  编写一个程序，它使用下列函数：
//   Fill_array( )将一个double数组的名称和长度作为参数。
//  它提示用户输入double值，并将这些值存储到数组中。
//  当数组被填满或用户输入了非数字时，输入将停止，并返回实际输入了多少个数字。
//  Show_array( )将一个double数组的名称和长度作为参数，并显示该数组的内容。
//  Reverse-array( )将一个double数组的名称和长度作为参数，并将存储在数组中的值的顺序反转。
//  程序将使用这些函数来填充数组，然后显示数组；反转数组，然后显示数组；
//  反转数组中除第一个和最后一个元素之外的所有元素，然后显示数组。
#include <iostream>
using namespace std;

int Fill_array(double *, int n);
void Show_array(double *, int n);
void Reverse_array(double *, int n);

int main()
{
    double arr[10] = {};
    int count = Fill_array(arr, 10);
    Show_array(arr, count);
    cout << endl;
    Reverse_array(arr, count);
    Show_array(arr, count);
    cout << endl;
    Reverse_array(arr + 1, count - 2);
    Show_array(arr, count);

    return 0;
}

int Fill_array(double *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "#" << i + 1 << ": ";
        if (cin >> arr[i])
            count++;
        else
        {
            cout << "Bad Input!\n\n";
            break;
        }
    }
    return count;
}

void Show_array(double *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << "#" << i + 1 << ": " << arr[i] << endl;
}

void Reverse_array(double *arr, int n)
{
    double temp;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}