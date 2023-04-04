#ifndef _PLORG_H_
#define _PLORG_H_

class Plorg{
private:
    char name[20];
    int CI;

public:
    Plorg(const char* name = "Plorga", int CI = 50);
    void set_CI(int CI);
    void show() const;
};

#endif