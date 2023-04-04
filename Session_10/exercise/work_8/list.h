#ifndef _LIST_H_
#define _LIST_H_

struct Item
{
    int n;
    Item *next;
};
class List
{
private:
    static const int Max = 10;
    int count;
    Item *head;
    Item *tail;
    Item *now;

public:
    List();
    ~List();
    int add();
    int isempty() const;
    int isfull() const;
    int reset();
    void show();
};

#endif