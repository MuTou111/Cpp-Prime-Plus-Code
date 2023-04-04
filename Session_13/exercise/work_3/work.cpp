#include <iostream>
#include <string>
#include "dma.h"
const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    DMA *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter 1 for baseDMA\t2 for lacksDMA\t3 for hasDMA\n";
        if (cin >> kind)
        {
            switch (kind)
            {
            case '1':
                p_clients[i] = new baseDMA();
                break;
            case '2':
                p_clients[i] = new lacksDMA();
                break;
            case '3':
                p_clients[i] = new hasDMA();
                break;
            default:
                cout << "Bad Input! Try Again!\n";
                i--;
                break;
            }
        }
        else
        {
            cout << "Bad Input! Try Again!\n";
            i--;
            while (cin.get() != '\n')
                ;
        }
    }
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->View();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i]; // free memory
    }
    cout << "Done.\n";

    return 0;
}