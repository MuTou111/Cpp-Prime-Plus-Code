#ifndef QUEUETP_H_
#define QUEUETP_H_
#include "workermi.h"

template <typename T>
class QueueTP
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head;
    Node *rear;

public:
    QueueTP();
    QueueTP(T[], int n);
    ~QueueTP();
    bool out(T &);
    bool in(T &);
    T &getRear();
};

template <typename T>
QueueTP<T>::QueueTP()
{
    head = new Node{T(), nullptr};
    rear = head;
}

template <typename T>
QueueTP<T>::QueueTP(T data[], int n)
{
    head = new Node{T(), nullptr};
    rear = head;
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node(data[i], nullptr);
        rear->next = temp;
        rear = rear->next;
    }
}

template <typename T>
QueueTP<T>::~QueueTP()
{
    while (head != nullptr)
    {
        Node *temp;
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
bool QueueTP<T>::in(T &in)
{
    Node *temp = new Node{in, nullptr};
    rear->next = temp;
    rear = rear->next;
    return true;
}

template <typename T>
bool QueueTP<T>::out(T &out)
{
    if (head != rear)
    {
        out = head->next->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    else
        return false;
}

template <typename T>
T &QueueTP<T>::getRear()
{
    return rear->data;
}

#endif