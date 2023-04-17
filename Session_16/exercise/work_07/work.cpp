#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Lotto(int, int);
void Show(int);

int main()
{
    vector<int> winners;
    winners = Lotto(100, 12);
    for_each(winners.begin(), winners.end(), Show);
    cout << endl;
}

vector<int> Lotto(int total, int count)
{
    vector<int> temp;
    vector<int> buffer;
    while (total > 0)
        buffer.push_back(total--);
    for (int i = 0; i < count; i++)
    {
        random_shuffle(buffer.begin(), buffer.end());
        temp.push_back(buffer.front());
    }
    return temp;
}

void Show(int n)
{
    cout << n << " ";
}