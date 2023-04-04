//  编写模板函数maxn( )，
//  它将由一个T类型元素组成的数组和一个表示数组元素数目的整数作为参数，
//  并返回数组中最大的元素。在程序对它进行测试，
//  该程序使用一个包含6个int元素的数组和一个包含4个double元素的数组来调用该函数。
//  程序还包含一个具体化，它将char指针数组和数组中的指针数量作为参数，
//  并返回最长的字符串的地址。如果有多个这样的字符串，则返回其中第一个字符串的地址。
//  使用由5个字符串指针组成的数组来测试该具体化。
#include <iostream>
#include <cstring>
using namespace std;
typedef char *ch;

template <class T>
T maxn(const T *, int);
template <>
char *maxn<char *>(char *const *, int);

int main()
{
    int int_array[6] = {3, 1, 21, 123, 23, 1};
    double dble_array[4] = {424.1, 424.1, 13.2, 123.2};
    char *ch_array[5] = {"abc", "abcd", "abcde", "abcd", "dasdada"};
    cout << "Max of int_array: " << maxn(int_array, 6) << endl;
    cout << "Max of dble_array: " << maxn(dble_array, 4) << endl;
    cout << "Longest of ch_array: " << maxn(ch_array, 5) << endl;
    return 0;
}

template <class T>
T maxn(const T array[], int n)
{
    T temp = array[0];
    for (int i = 1; i < n; i++)
        if (temp < array[i])
            temp = array[i];
    return temp;
}

template <>
char *maxn<char *>(char *const *array, int n)
{
    char *temp = array[0];
    for (int i = 1; i < n; i++)
        if (strlen(temp) < strlen(array[i]))
            temp = array[i];
    return temp;
}