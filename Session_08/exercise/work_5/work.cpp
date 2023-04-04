//  编写模板函数max5( )，它将一个包含5个T类型元素的数组作为参数，
//  并返回数组中最大的元素（由于长度固定，因此可以在循环中使用硬编码，
//  而不必通过参数来传递）。在一个程序中使用该函数，
//  将T替换为一个包含5个int值的数组和一个包含5个dowble值的数组，以测试该函数。
#include <iostream>
using namespace std;

template <class T>
T max5(T *data);

int main()
{
    int int_array[5] = {12, 54, 1634, 23, 14231};
    double dble_array[5] = {1.3, 424.3, 23.5, 131.2, 15423.2};
    cout << "Max of int_array: " << max5(int_array) << endl;
    cout << "Max of dnle_array: " << max5(dble_array) << endl;

    return 0;
}

template <class T>
T max5(T *data)
{
    T temp = data[0];
    for (int i = 1; i < 5; i++)
        if (temp < data[i])
            temp = data[i];
    return temp;
}