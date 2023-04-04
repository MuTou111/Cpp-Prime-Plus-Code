#include <iostream>
#include "person.h"

int main()
{
    Person one;
    Person two("Smythcraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    cout << endl;
    one.FormalShow();
    cout << endl;
    two.Show();
    cout << endl;
    two.FormalShow();
    cout << endl;
    three.Show();
    cout << endl;
    three.FormalShow();

    return 0;
}