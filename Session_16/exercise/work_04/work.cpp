#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
int reduce(long ar[], int n);

int main()
{
    long arr[10] = {1, 4, 6, 2, 4, 6, 1, 10, 3, 7};
    int n = reduce(arr, 10);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

int reduce(long ar[], int n)
{
    vector<long> temp(n);
    vector<long>::iterator index;

    copy(ar, ar + n, temp.begin());
    sort(temp.begin(), temp.end());
    index = unique(temp.begin(), temp.end());
    temp.resize(index - temp.begin());
    copy(temp.begin(), temp.end(), ar);
    return temp.size();
}