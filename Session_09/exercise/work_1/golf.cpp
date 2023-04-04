#include "golf.h"
#include <iostream>
#include <cstring>

void setgolf(golf &g, const char *name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf &g)
{
    using namespace std;
    cout << "Enter the name: ";
    cin.getline(g.fullname, 40);
    if (g.fullname[0] == '\0')
        return 0;
    cout << "Enter the handicap: ";
    cin >> g.handicap;
    while (!cin)
    {
        cin.clear();
        while (cin.get() != '\n')
            ;
        cout << "\nError Input, try again!\n";
        cout << "Enter the handicap: ";
        cin >> g.handicap;
    }
    while (cin.get() != '\n')
        ;
    return 1;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    using namespace std;
    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}