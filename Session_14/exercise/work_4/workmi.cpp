// workmi.cpp ----- multiple inheritance
// compile with wokermi.cpp
#include <iostream>
#include <cstring>
#include "baddude.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Person *lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
             << "p: pokerplayer\tg: gunslinger\t"
             << "b: baddude\tq: quit\n";
        cin >> choice;
        while (strchr("pgbq", choice) == NULL)
        {
            cout << "Please enter a p, g, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'p':
            lolas[ct] = new PokerPlayer;
            break;
        case 'g':
            lolas[ct] = new Gunslinger;
            break;
        case 'b':
            lolas[ct] = new BadDude;
            break;
        }
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n";

    return 0;
}