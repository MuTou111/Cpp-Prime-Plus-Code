#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

void Get(list<string> &);
list<string> Merge(list<string> &, list<string> &);
void Show(const string &);

int main()
{
    list<string> L1, L2, L3;
    cout << "Mat entered the list(q to quit):\n";
    Get(L1);
    cout << "\n\nShow Mat's List:\n";
    for_each(L1.begin(), L1.end(), Show);
    cout << "\n\nPat entered the list(q to quit):\n";
    Get(L2);
    cout << "\n\nShow Pat's List:\n";
    for_each(L2.begin(), L2.end(), Show);

    L3 = Merge(L1, L2);
    cout << "\n\nTotal List:\n";
    for_each(L3.begin(), L3.end(), Show);

    return 0;
}

void Get(list<string> &L)
{
    string temp;
    while (cin >> temp && temp != "q")
        L.push_back(temp);
    L.sort();
}

list<string> Merge(list<string> &L1, list<string> &L2)
{
    list<string> temp;
    for(string str : L1)
        temp.push_back(str);
    for(string str : L2)
        temp.push_back(str);
    temp.sort();
    temp.unique();
    return temp;
}

void Show(const string &str)
{
    cout << str << endl;
}