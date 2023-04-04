#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "base.h"

class Classic : public Cd
{
private:
    char *name;

public:
    Classic(const char *s, char *s1, char *s2, int n, double x);
    Classic(const char *s, const Cd &c);
    Classic(const Classic &c);
    Classic();
    ~Classic();
    void Report() const;
    Classic &operator=(const Classic &c);
};

#endif