#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

template <class T>
int reduce(T ar[], int n);

int main()
{
    long arr1[] = {1, 3, 4, 2, 3, 16, 23, 45};
    string arr2[] = {"abc", "sbd", "wds", "cds", "ujs", "ajf", "ehc", "ajf"};
    int count1, count2;
    count1 = reduce(arr1, 8);
    count2 = reduce(arr2, 8);
    cout << count1 << ":\n";
    for (int i = 0; i < count1; i++)
        cout << arr1[i] << " ";
    cout << endl;
    cout << count2 << ":\n";
    for (int i = 0; i < count2; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}

template <class T>
int reduce(T ar[], int n)
{
    set<T> temp;
    for (int i = 0; i < n; i++)
    {
        temp.insert(ar, ar + n);
    }
    copy(temp.begin(), temp.end(), ar);

    return temp.size();
}