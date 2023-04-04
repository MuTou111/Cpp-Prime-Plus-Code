#include <iostream>
#include <cstring>
#include "person.h"

Person::Person(const string &ln, const char *fn)
{
    this->lname = ln;
    strcpy(this->fname, fn);
}

void Person::Show() const
{
    cout << this->fname << " " << this->lname << endl;
}

void Person::FormalShow() const
{
    cout << this->lname << ", " << this->fname << endl;
}