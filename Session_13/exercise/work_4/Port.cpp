#include "Port.h"
#include <cstring>
#include <iostream>

Port::Port(const char *br, const char *st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strncpy(style, st, 20);
    bottles = b;
}

Port::Port(const Port *p)
{
    brand = new char[strlen(p->brand) + 1];
    strcpy(brand, p->brand);
    strncpy(style, p->style, 20);
    bottles = p->bottles;
}

Port &Port::operator=(const Port &p)
{
    if (this == &p)
        return *this;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 20);
    bottles = p.bottles;
    return *this;
}

Port &Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port &Port::operator-=(int b)
{
    if (bottles <= 0)
        cout << "No more!" << endl;
    else if (bottles < b)
        cout << "Not Enough!" << endl;
    else
        bottles -= b;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream &operator<<(ostream &os, const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles << " ";
    return os;
}