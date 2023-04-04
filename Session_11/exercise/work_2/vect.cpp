//  vect.cpp ------- methods for the Vector class
#include "vect.h"
#include <cmath>
using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::sqrt;

namespace VECTOR
{
    // compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0);
    // should be about 57.2957795130823

    // private methods
    // calculates magnitude form x and y
    // void Vector::set_mag()
    // {
    //     mag = sqrt(x * x + y * y);
    // }

    // void Vector::set_ang()
    // {
    //     if (x == 0.0 && y == 0.0)
    //         ang = 0.0;
    //     else
    //         ang = atan2(y, x);
    // }

    double Vector::magval() const
    {
        return sqrt(x * x + y * y);
    }

    double Vector::angval() const
    {
        if (x == 0.0 && y == 0.0)
            return 0.0;
        else
            return atan2(y, x);
    }

    // set x from polar coordinate
    void Vector::set_x(double mag, double ang)
    {
        x = mag * cos(ang);
    }

    // set y from polar coordinate
    void Vector::set_y(double mag, double ang)
    {
        y = mag * sin(ang);
    }

    // public methods
    Vector::Vector() // default constructor
    {
        x = y = 0.0;
        mode = RECT;
    }

    // construct vector from rectangular coordinates if form is r
    // (the default) or else from polar coordinates if form is p
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            set_x(mag, ang);
            set_y(mag, ang);
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    // reset vector from rectangular coordinates if form is
    // RECT (the default) or else from polar coordinates if
    // form is POL
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            set_x(mag, ang);
            set_y(mag, ang);
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector() // destructor
    {
    }

    void Vector::polar_mode() // set to polar mode;
    {
        mode = POL;
    }

    void Vector::rect_mode() // set tot rectangular mode
    {
        mode = RECT;
    }

    //  operator overloading
    //  add two Vectors
    Vector Vector::operator+(const Vector &b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    // subtract Vector b from a
    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // reverse sign of Vector
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    Vector operator*(double n, const Vector &a) // friend function
    {
        return a * n; // convert double times Vector to Vector times double
    }

    // display rectangular coordinates if mode is RECT,
    // else dieplay polar coordinates if mode is POL
    std::ostream &operator<<(std::ostream &os, const Vector &v)
    {
        if (v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.magval() << ", "
               << v.angval() * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invalid";
        return os;
    }
}