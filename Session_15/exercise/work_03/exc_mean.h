// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <string>

class error : public std::logic_error
{
protected:
    double v1;
    double v2;

public:
    error(double a = 0, double b = 0,
          const std::string &s = "Error!\n") : std::logic_error(s), v1(a), v2(b) {}
    virtual void mesg() = 0;
};

class bad_hmean : public error
{
public:
    bad_hmean(double a = 0, double b = 0,
              const std::string &s = "Error in hmean()!\n") : error(a, b, s) {}
    void mesg();
    const char *waht() { return std::logic_error::what(); }
};

inline void bad_hmean::mesg()
{
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean : public error
{
public:
    bad_gmean(double a = 0, double b = 0,
              const std::string &s = "Error in gmean()!\n") : error(a, b, s) {}
    void mesg();
    const char *waht() { return std::logic_error::what(); }
};

void bad_gmean::mesg()
{
    std::cout << "gmean(" << v1 << ", " << v2 << "): "
              << "invalid arguments: a < 0 or b < 0.\n";
}