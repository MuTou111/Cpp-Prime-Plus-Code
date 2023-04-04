#include "stack.h"
#include <iostream>

using namespace std;

void add(Stack &);
void del(Stack &);

int main()
{
    Stack stack;
    char ch;
    while (1)
    {
        cout << "a) add\tb) del\tq) quit\n";
        cin.get(ch);
        while (cin.get() != '\n')
            ;
        switch (ch)
        {
        case 'a':
            add(stack);
            break;
        case 'b':
            del(stack);
            break;
        case 'q':
            exit(EXIT_SUCCESS);
        default:
            cout << "Error input, try again.\n";
        }
    }

    return 0;
}

void add(Stack &stack)
{
    if (!stack.isfull())
    {
        customer cstr;
        cout << "Enter name: ";
        cin.getline(cstr.fullname, 35);
        cout << "Enter the payment: ";
        cin >> cstr.payment;
        while (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "\nError Input, try again!\n";
            cout << "Enter the payment: ";
            cin >> cstr.payment;
        }
        while (cin.get() != '\n')
            ;
        stack.push(cstr);
    }
    else
        cout << "Stack is full!!!\n";
}

void del(Stack &stack)
{
    static double sum = 0;
    customer cstr;
    if (!stack.isempty())
    {
        stack.pop(cstr);
        sum += cstr.payment;
        cout << "Total Paymanet: " << sum << endl;
    }
    else
        cout << "Empty Stack!!!\n";
}