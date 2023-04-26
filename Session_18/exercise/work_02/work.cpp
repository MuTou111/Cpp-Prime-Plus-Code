#include <iostream>
#include <string>

class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };

private:
    Info *pi;

public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv &cp);
    Cpmv(Cpmv &&mv);
    ~Cpmv();
    Cpmv &operator=(const Cpmv &cp);
    Cpmv &operator=(Cpmv &&mv);
    Cpmv operator+(const Cpmv &obj) const;
    void Display() const;
};

Cpmv::Cpmv()
{
    std::cout << "Default constructor" << std::endl;
    pi = new Info{};
}

Cpmv::Cpmv(std::string q, std::string z)
{
    std::cout << "Constructor with two args" << std::endl;
    pi = new Info{q, z};
}

Cpmv::Cpmv(const Cpmv &cp)
{
    std::cout << "Copy Constructor" << std::endl;
    pi = new Info{cp.pi->qcode, cp.pi->zcode};
}

Cpmv::Cpmv(Cpmv &&mv)
{
    std::cout << "Move Constructor" << std::endl;
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
    std::cout << "Deconstructor" << std::endl;
    delete pi;
}

Cpmv &Cpmv::operator=(const Cpmv &cp)
{
    std::cout << "operactor=(const Cpmv &cp)" << std::endl;
    if (this == &cp)
        return *this;
    this->pi->qcode = cp.pi->qcode;
    this->pi->zcode = cp.pi->zcode;

    return *this;
}

Cpmv &Cpmv::operator=(Cpmv &&mv)
{
    std::cout << "operator=(Cpmv &&mv)" << std::endl;
    if (this == &mv)
        return *this;
    this->pi = mv.pi;
    mv.pi = nullptr;

    return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
    std::cout << "operator+(const Cpmv &obj)" << std::endl;
    Cpmv temp(this->pi->qcode + obj.pi->qcode, this->pi->zcode + obj.pi->zcode);
    return temp;
}

void Cpmv::Display() const
{
    std::cout << this->pi->qcode << std::endl;
    std::cout << this->pi->zcode << std::endl;
}

int main()
{
    Cpmv c1("A", "B");
    c1.Display();
    Cpmv c2(c1);
    c2.Display();
    Cpmv c3(c1 + c2);
    c3.Display();
    Cpmv c4;
    c4 = c1;
    c4.Display();
    Cpmv c5;
    c5 = c1 + c2;
    c5.Display();

    return 0;
}