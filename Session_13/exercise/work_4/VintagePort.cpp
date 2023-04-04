#include "VintagePort.h"
#include <iostream>
#include <cstring>

VintagePort::VintagePort()
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "vintage", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
        return *this;
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    cout << "NickName: " << nickname << endl;
    cout << "Year: " << year << endl;
    Port::Show();
}

ostream &operator<<(ostream &os, const VintagePort &vp)
{
    os << vp.nickname << ", " << vp.year << ", " << (Port &)vp;
    return os;
}