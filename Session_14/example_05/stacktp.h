// stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_
template <class Type>
class Stack
{
private:
    enum
    {
        Max = 10
    };               // constant specific to class
    Type items[Max]; // holds stack items
    int top;         // index for top stack item

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Type &item); // add item to stack
    bool pop(Type &item);        // pop top into item
};

template <class Type>
Stack<Type>::Stack()
{
    top = 0;
}

template <class Type>
bool Stack<Type>::isempty()
{
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull()
{
    return top == Max;
}

template <class Type>
bool Stack<Type>::push(const Type &item)
{
    if (top < Max)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool Stack<Type>::pop(Type &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

#endif