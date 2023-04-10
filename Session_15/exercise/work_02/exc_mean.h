// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <string>

class bad_hmean : public std::logic_error
{
public:
    bad_hmean(const std::string &s = "Error in hmean()!\n") : std::logic_error(s){}
    const char *waht() { return std::logic_error::what(); }
};

class bad_gmean : public std::logic_error
{
public:
    bad_gmean(const std::string &s = "Error in gmean()!\n") : std::logic_error(s){}
    const char *waht() {return std::logic_error::what();}
};