#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin1("mat.dat");
    ifstream fin2("pat.dat");
    ofstream fout("mantnpat.dat");

    list<string> l1;
    string temp;

    while (getline(fin1, temp))
        l1.push_back(temp);

    while (getline(fin2, temp))
        l1.push_back(temp);

    l1.sort();
    l1.unique();

    while (l1.size() > 0)
    {
        fout << l1.front() << endl;
        l1.pop_front();
    }

    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}