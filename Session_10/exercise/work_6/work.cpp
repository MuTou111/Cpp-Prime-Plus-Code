#include "move.h"
#include <iostream>

using namespace std;

int main()
{
    Move move_1(100, 100);
    move_1.showmove();
    Move move_2(100, 100);
    move_1 = move_1.add(move_2);
    move_1.showmove();
    move_1.reset();
    move_1.showmove();

    return 0;
}