#include "golf.h"
#include <iostream>
#include <cstring>

golf::golf(const char *name, int hc)
{
    strcpy(this->fullname, name);
    this->handicap = hc;
}

void golf::setgolf()
{
    using namespace std;
    cout << "Enter the name: ";
    char name[40];
    cin.getline(name, 40);
    if (name[0] == '\0')
        exit(EXIT_FAILURE);
    cout << "Enter the handicap: ";
    int handicap;
    cin >> handicap;
    while (!cin)
    {
        cin.clear();
        while (cin.get() != '\n')
            ;
        cout << "\nError Input, try again!\n";
        cout << "Enter the handicap: ";
        cin >> handicap;
    }
    while (cin.get() != '\n')
        ;
    *this = golf(name, handicap);
}

void golf::set_handicap(int hc)
{
    this->handicap = hc;
}

void golf::showgolf() const
{
    using namespace std;
    cout << "Name: " << this->fullname << endl;
    cout << "Handicap: " << this->handicap << endl;
}