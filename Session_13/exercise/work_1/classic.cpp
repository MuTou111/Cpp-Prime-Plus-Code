#include "classic.h"
#include <cstring>
#include <iostream>
using namespace std;
Classic::Classic(const char *s, char *s1, char *s2, int n, double x) : Cd(s1, s2, n, x)
{
    name = new char[strlen(s) + 1];
    strcpy(name, s);
}

Classic::Classic(const char *s, const Cd &c) : Cd(c)
{
    name = new char[strlen(s) + 1];
    strcpy(name, s);
}

Classic::Classic(const Classic &c) : Cd(c)
{
    name = new char[strlen(c.name) + 1];
    strcpy(name, c.name);
}

Classic::Classic()
{
    name = new char[1];
    name[0] = '\0';
}

Classic::~Classic()
{
    delete[] name;
}

void Classic::Report() const
{
    cout << "Name: " << name << endl;
    Cd::Report();
}

Classic &Classic::operator=(const Classic &c)
{
    if (this == &c)
        return *this;
    delete[] name;
    name = new char[strlen(c.name) + 1];
    strcpy(name, c.name);
    Cd::operator=(c);
    return *this;
}