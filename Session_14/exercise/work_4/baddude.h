#ifndef BADDUDE_H_
#define BADDUDE_H_
#include "gunslinger.h"
#include "pokerplayer.h"

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude() {}
    BadDude(string &fn, string &ln, double t, int c, int n) : Person(fn, ln), Gunslinger(fn, ln, t, c), PokerPlayer(fn, ln, n) {}
    double Gdraw();
    int Cdraw();
    void Show() const;
    void Set();
};

double BadDude::Gdraw()
{
    return Gunslinger::Draw();
}

int BadDude::Cdraw()
{
    return PokerPlayer::Draw();
}

void BadDude::Show() const
{
    Person::Show();
    Gunslinger::Data();
    PokerPlayer::Data();
}

void BadDude::Set()
{
    Person::Get();
    Gunslinger::Get();
    PokerPlayer::Get();
}

#endif