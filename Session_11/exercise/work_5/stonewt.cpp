//  stonewt.cpp ----- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn; // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = POUND;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn;
    mode = STONE;
}

Stonewt::Stonewt() // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    mode = POUND;
}

Stonewt::~Stonewt() // destructor
{
}

Stonewt &Stonewt::set_mode(Mode m)
{
    mode = m;
    return *this;
}

// show weight in stones
// void Stonewt::show_stn() const
// {
//     cout << stone << " stone, " << pds_left << " pounds\n";
// }

// show weight in poumds
// void Stonewt::show_lbs() const
// {
//     cout << pounds << " pounds\n";
// }

Stonewt Stonewt::operator+(const Stonewt &t) const
{
    return Stonewt(pounds + t.pounds);
}

Stonewt Stonewt::operator-(const Stonewt &t) const
{
    return Stonewt(pounds - t.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(pounds * n);
}

std::ostream &operator<<(std::ostream &os, const Stonewt &s)
{
    switch (s.mode)
    {
    case Stonewt::STONE:
        os << s.stone << " stone, " << s.pds_left << " pounds\n";
        break;
    case Stonewt::POUND:
        os << s.pounds << " pounds\n";
        break;
    }
    return os;
}