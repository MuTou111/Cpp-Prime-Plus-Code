#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    Stack st1, st2(5), st3;
    cout << "Push st1 and st2:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "st1 push!\n";
        st1.push(i);
        cout << "st2 push!\n";
        st2.push(i);
        cout << "st3 push!\n";
        st3.push(i);
    }
    cout << "Pop st1 and st2:\n";
    Item temp;
    for (int i = 0; i < 10; i++)
    {
        st1.pop(temp);
        cout << "st1 pop\n"
             << temp << endl;
        st2.pop(temp);
        cout << "st2 pop\n"
             << temp << endl;
    }
    st2 = st3;
    cout << "Pop st2 again:\n";
    for (int i = 0; i < 10; i++)
    {
        st2.pop(temp);
        cout << "st2 pop\n"
             << temp << endl;
    }

    return 0;
}