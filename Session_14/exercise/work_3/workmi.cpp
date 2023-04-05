// workmi.cpp ----- multiple inheritance
// compile with wokermi.cpp
#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queuetp.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    // Worker *lolas[SIZE];
    QueueTP<Worker *> queue;

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter\ts: singer\t"
             << "t: singing waiter\tq: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        Worker *temp;
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':
            temp = new Waiter;
            break;
        case 's':
            temp = new Singer;
            break;
        case 't':
            temp = new SingingWaiter;
            break;
        }
        queue.in(temp);
        cin.get();
        queue.getRear()->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    Worker *temp;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        queue.out(temp);
        temp->Show();
    }
    cout << "Bye.\n";

    return 0;
}