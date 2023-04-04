#include "complex0.h"

Complex::Complex(double r, double i)
{
    this->R = r;
    this->I = i;
}

Complex Complex::operator+(const Complex &c) const
{
    return Complex(R + c.R, I + c.I);
}

Complex Complex::operator-(const Complex &c) const
{
    return Complex(R - c.R, I - c.I);
}

Complex Complex::operator*(const Complex &c) const
{
    return Complex(R * c.R - I * c.I, R * c.I + I * c.R);
}

Complex operator*(double n, Complex &c)
{
    return Complex(n * c.R, n * c.I);
}

Complex Complex::operator~() const
{
    return Complex(R, -I);
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    os << "(" << c.R << ", " << c.I << "i)";
    return os;
}

std::istream &operator>>(std::istream &os, Complex &c)
{
    std::cout << "real: ";
    if (!(os >> c.R))
        return os;
    std::cout << "imaginary: ";
    if (!(os >> c.I))
        return os;
}