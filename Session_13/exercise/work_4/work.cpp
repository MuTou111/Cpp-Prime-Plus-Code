#include "VintagePort.h"
#include <iostream>

int main()
{
    VintagePort v1("A", 0, "The Noble", 1946);
    VintagePort v2("B", 10, "Old Velevt", 1956);
    v1.Show();
    cout << endl;
    v2.Show();
    cout << endl;
    VintagePort v3(v2);
    v3.Show();
    cout << endl;
    Port p1(v2);
    p1.Show();
    cout << endl;

    cout << v1 << endl
         << v2 << endl
         << v3 << endl
         << p1 << endl;

    return 0;
}