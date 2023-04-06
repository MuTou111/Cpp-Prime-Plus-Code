#ifndef POKERPLAYER_H_
#define POKERPLAYER_H_
#include "person.h"
#include <cstdlib>
#include <ctime>

class PokerPlayer : virtual public Person
{
private:
    int number;

public:
    PokerPlayer(){};
    PokerPlayer(string &fn, string &ln, int num) : Person(fn, ln), number(num) {}
    ~PokerPlayer() {}
    int Draw();
    int GetNum() const;
    void Data() const;
    void Show() const;
    void Get();
    void Set();
};

int PokerPlayer::GetNum() const
{
    return number;
}

int PokerPlayer::Draw()
{
    srand(time(0));
    number = (rand() % 52) + 1;
    return number;
}

void PokerPlayer::Data() const
{
    std::cout << "Card: " << number << std::endl;
}

void PokerPlayer::Show() const
{
    Person::Show();
    std::cout << "Card: " << number << std::endl;
}

void PokerPlayer::Get()
{
    Draw();
    std::cout << "Got a Card!\n";
}

void PokerPlayer::Set()
{
    Person::Get();
    Get();
}

#endif