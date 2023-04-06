#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>
using std::string;

class Person
{
private:
    string firstname;
    string lastname;

protected:
    void Get();

public:
    Person() {}
    Person(const string &fn, const string &ln) : firstname(fn), lastname(ln) {}
    virtual ~Person() = 0;
    void virtual Show() const;
    void virtual Set() = 0;
};

void Person::Get()
{
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Enter the first name: ";
    getline(cin, firstname);
    cout << "Enter the last name: ";
    getline(cin, lastname);
}

Person::~Person() {}

void Person::Show() const
{
    using std::cout;
    using std::endl;
    cout << "FullName: " << firstname << ", " << lastname << endl;
}

#endif