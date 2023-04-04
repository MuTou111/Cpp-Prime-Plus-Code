//  stonewt.h --------- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
public:
    enum Mode
    {
        STONE = 1,
        POUND = 2
    };

private:
    enum
    {
        Lbs_per_stn = 14
    };               // pounds per stone
    int stone;       // whole stones
    double pds_left; // fractional pounds
    double pounds;   // entire weight in pounds
    Mode mode;

public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    Stonewt & set_mode(Mode m);
    // void show_lbs() const; // show weight in pounds format
    // void show_stn() const; // show weight in stone format
    Stonewt operator+(const Stonewt &t) const;
    Stonewt operator-(const Stonewt &t) const;
    Stonewt operator*(double n) const;
    friend Stonewt operator*(double n, const Stonewt &t) { return t * n; };
    friend std::ostream &operator<<(std::ostream &os, const Stonewt &s);
};

#endif