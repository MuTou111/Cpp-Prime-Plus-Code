#include <iostream>

class Complex
{
private:
    double R;
    double I;

public:
    Complex(double r = 0, double i = 0);
    ~Complex(){};
    Complex operator+(const Complex &c) const;
    Complex operator-(const Complex &c) const;
    Complex operator*(const Complex &c) const;
    friend Complex operator*(double n, Complex &c);
    Complex operator~() const;
    friend std::istream &operator>>(std::istream &os, Complex &c);
    friend std::ostream &operator<<(std::ostream &os, const Complex &c);
};