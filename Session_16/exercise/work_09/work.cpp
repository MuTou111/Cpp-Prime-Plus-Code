#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 10000000;

int main()
{
    vector<int> vi0;
    srand(time(0));
    for (int i = 0; i < SIZE; i++)
        vi0.push_back(rand() % SIZE);

    vector<int> vi(SIZE);
    list<int> li(SIZE);
    copy(vi0.begin(), vi0.end(), vi.begin());
    copy(vi0.begin(), vi0.end(), li.begin());
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "Time of sort with vector:"
         << (double)(end - start) / CLOCKS_PER_SEC
         << endl;

    start = clock();
    li.sort();
    end = clock();
    cout << "Time of sort with list:"
         << (double)(end - start) / CLOCKS_PER_SEC
         << endl;

    return 0;
}