#ifndef GUNSLINGER_H_
#define GUNSLINGER_H_
#include "person.h"

class Gunslinger : virtual public Person
{
private:
    double time;
    int count;

public:
    Gunslinger() {}
    Gunslinger(const string &fn, const string &ln, double t, int c) : Person(fn, ln), time(t), count(c) {}
    Gunslinger(const Person &p, double t, int c) : Person(p), time(t), count(c) {}
    void Set();
    void Get();
    double Draw() const;
    void Data() const;
    void Show() const;
};

void Gunslinger::Set()
{
    Person::Get();
    Get();
}

void Gunslinger::Get()
{
    std::cout << "Enter the time: ";
    std::cin >> time;
    std::cout << "Enter the count: ";
    std::cin >> count;
    while (std::cin.get() != '\n')
        continue;
}

double Gunslinger::Draw() const
{
    return time;
}

void Gunslinger::Data() const
{
    std::cout << "Time: " << time << "\nCount: " << count << std::endl;
}

void Gunslinger::Show() const
{
    Person::Show();
    std::cout << "Time: " << time << "\nCount: " << count << std::endl;
}

#endif