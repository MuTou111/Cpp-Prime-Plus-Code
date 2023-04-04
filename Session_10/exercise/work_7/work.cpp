#include "Plorg.h"
#include <iostream>

using namespace std;

int main()
{
    Plorg p_1 = Plorg("A");
    Plorg p_2 = Plorg("B", 2);
    p_1.show();
    p_2.show();
    p_1.set_CI(10);
    p_1.show();
    p_2.set_CI(20);
    p_2.show();

    return 0;
}