// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <string>

class bad_hmean : public std::logic_error
{
private:
    double v1;
    double v2;

public:
    bad_hmean(double a = 0, double b = 0,
              const std::string &s = "Error in hmean()!\n") : std::logic_error(s), v1(a), v2(b) {}
    void mesg();
    const char *waht() { return std::logic_error::what(); }
};

inline void bad_hmean::mesg()
{
    std::cout << "hmean(" << v1 << ", " << 2 << "): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean : public std::logic_error
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0,
              const std::string &s = "Error in gmean()!\n") : std::logic_error(s), v1(a), v2(b) {}
    const char *mesg();
    const char *waht() {return std::logic_error::what();}
};

inline const char *bad_gmean::mesg()
{
    return "gmean() arguments shouble be >= 0\n";
}