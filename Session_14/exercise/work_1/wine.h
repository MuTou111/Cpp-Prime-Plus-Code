#ifndef WINE_H_
#define WINE_H_
#include "pair.h"
#include <valarray>
#include <cstring>
#include <iostream>
using Array = std::valarray<int>;
using std::cin;
using std::cout;
using std::endl;

class Wine : private Pair<Array, Array>
{
private:
    char name[50];
    int n;

public:
    Wine() : Pair(Array(0), Array(0)), n(0)
    {
        name[0] = '\0';
    }
    Wine(const char *l, int y, const int yr[], const int bot[]);
    Wine(const char *l, int y);
    void GetBottles();
    const char *Label() const { return name; }
    void Show() const;
    int sum() const;
};

Wine::Wine(const char *l, int y, const int yr[], const int bot[]) : Pair(Array(yr, y), Array(bot, y))
{
    strcpy(name, l);
    n = y;
}

Wine::Wine(const char *l, int y) : Pair()
{
    strcpy(name, l);
    n = y;
}

void Wine::GetBottles()
{
    Pair::first().resize(n, 0);
    Pair::second().resize(n, 0);
    while (cin.get() != '\n')
        continue;
    int year, bottle;
    cout << "Enter " << name << " data for " << n << " year(s):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the year: ";
        if (!(cin >> year))
        {
            cout << "Error Input!\n";
            i--;
            continue;
        }
        cout << "Enter bottles for that year: ";
        if (!(cin >> bottle))
        {
            cout << "Error Input!\n";
            i--;
            continue;
        }
        Pair::first()[i] = year;
        Pair::second()[i] = bottle;
    }
}

void Wine::Show() const
{
    cout << "Wine: " << name << endl;
    cout << "\tYear\tBottles\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << Pair::first()[i] << "\t" << Pair::second()[i] << endl;
    }
}

int Wine::sum() const
{
    return Pair::second().sum();
}

#endif