#include "move.h"
#include <iostream>

using namespace std;

Move::Move(double a, double b)
{
    this->x = a;
    this->y = b;
}

void Move::showmove() const
{
    cout << "X: " << this->x << endl;
    cout << "Y: " << this->y << endl;
}

Move Move::add(const Move &m) const
{
    Move move;
    move.x = this->x + m.x;
    move.y = this->y + m.y;
    return move;
}

void Move::reset(double a, double b)
{
    this->x = a;
    this->y = b;
}