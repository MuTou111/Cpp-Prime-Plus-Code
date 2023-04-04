#include "list.h"
#include <iostream>

List::List()
{
    this->count = 0;
    this->head = new Item();
    this->tail = this->head;
    this->now = NULL;
}

List::~List()
{
    this->now = this->head->next;
    while (this->now)
    {
        free(this->head);
        this->head = this->now;
        this->now = this->head->next;
    }
}

int List::add()
{
    using namespace std;
    Item *item = new Item();
    cout << "Enter the data(int): ";
    cin >> item->n;
    while (!cin)
    {
        cout << "Mismatch! Try again: ";
        cin.clear();
        while (cin.get() != '\n')
            ;
        cin >> item->n;
    }
    this->tail->next = item;
    this->tail = this->tail->next;
    this->now = this->tail;
    count++;
}

int List::isempty() const
{
    if (count > 0)
        return 0;
    else
        return 1;
}

int List::isfull() const
{
    if (count < 10)
        return 0;
    else
        return 1;
}

int List::reset()
{
    using namespace std;
    cout << "Enter number of List: ";
    int n;
    cin >> n;
    while (!cin)
    {
        cout << "Mismatch! Try again: ";
        cin.clear();
        while (cin.get() != '\n')
            ;
        cin >> n;
    }
    if (n < 0 || n > count)
    {
        cout << "Out Range!";
        return 0;
    }
    this->now = this->head;
    for (int i = 0; i < n; i++)
        now = now->next;

    cout << "Enter the data: ";
    cin >> n;
    while (!cin)
    {
        cout << "Mismatch! Try again: ";
        cin.clear();
        while (cin.get() != '\n')
            ;
        cin >> n;
    }
    now->n = n;
    return 1;
}

void List::show()
{
    using namespace std;
    this->now = this->head->next;
    for(int i = 0; i < count;i++)
    {
        cout << "#" << i+1 << endl;
        cout << "Data: " << this->now->n << endl;
        this->now = this->now->next;
    }
}