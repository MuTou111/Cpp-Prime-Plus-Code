#include "Plorg.h"
#include <iostream>
#include <cstring>

using namespace std;

Plorg::Plorg(const char *name, int CI)
{
    strcpy(this->name, name);
    this->CI = CI;
}

void Plorg::set_CI(int CI)
{
    this->CI = CI;
}

void Plorg::show() const
{
    cout << "Name: " << this->name << endl;
    cout << "CI: " << this->CI << endl;
}