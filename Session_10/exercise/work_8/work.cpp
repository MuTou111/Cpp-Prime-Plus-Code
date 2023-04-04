#include "list.h"
#include <iostream>

using namespace std;

int main()
{
    List l;
    while (!l.isfull())
    {
        l.add();
    }
    l.show();
    l.reset();
    l.show();

    return 0;
}