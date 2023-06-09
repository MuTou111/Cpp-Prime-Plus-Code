// rtti2.cpp ---- using dynamic_cast, typeid, and type_info
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using namespace std;
class Grand
{
private:
    int hold;

public:
    Grand(int h = 0) : hold(h) {}
    virtual void Speak() const { cout << "I am a grand class!\n"; }
    virtual int Vlaue() const { return hold; }
};

class Superb : public Grand
{
public:
    Superb(int h = 0) : Grand(h) {}
    void Speak() const { cout << "I am a superb class!!\n"; }
    virtual void Say() const
    {
        cout << "I hold the superb value of " << Vlaue() << "!\n";
    }
};

class Magnificent : public Superb
{
private:
    char ch;

public:
    Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
    void Speak() const { cout << "I am a magnificent class!!!\n"; }
    void Say() const { cout << "I hold the character " << ch << " and the integer " << Vlaue() << "!\n"; }
};

Grand *GetOne();
int main()
{
    std::srand(std::time(0));
    Grand *pg;
    Superb *ps;
    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        pg->Speak();
        if (ps = dynamic_cast<Superb *>(pg))
            ps->Say();
        if (typeid(Magnificent) == typeid(*pg))
            cout << "Yes, you're really magnificent.\n";
    }

    return 0;
}

Grand *GetOne() // generate one of three kinds of objects randomly
{
    Grand *p;
    switch (std::rand() % 3)
    {
    case 0:
        p = new Grand(std::rand() % 100);
        break;
    case 1:
        p = new Superb(std::rand() % 100);
        break;
    case 2:
        p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 261);
        break;
    }
    return p;
}