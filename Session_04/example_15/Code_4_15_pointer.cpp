//  pointer.cpp -------------- our first pointer variable
#include <iostream>
int main()
{
    using namespace std;
    int updates = 6;
    int * p_updates;                //  declare a variable
    p_updates = &updates;      //  declare pointer to an int

    //express values two ways
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    //express address two ways
    cout << "Addrresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    //use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    return 0;
}