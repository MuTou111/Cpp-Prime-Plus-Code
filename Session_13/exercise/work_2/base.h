#ifndef BASE_H_
#define BASE_H_
// base class
class Cd
{ // repersents a CD disk
private:
    char *performers;
    char *label;
    int selections;  // number of selections
    double playtime; // playing time in minutes

public:
    Cd(char *s1, char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    ~Cd();
    virtual void Report() const; // reports all CD data
    virtual Cd &operator=(const Cd &d);
};

#endif