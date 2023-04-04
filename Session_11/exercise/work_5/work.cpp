//  stone.cpp -------- user-definrd conversions
// compile with stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt &st, int n);
int main()
{
    using std::endl;
    Stonewt incognito = 275; // uses constructor to initialize
    Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7
    Stonewt taft(21, 8);

    cout << "The celebrity weighed " << incognito.set_mode(Stonewt::STONE) << endl;
    // incognito.show_stn();
    cout << "The detective weighed " << wolfe.set_mode(Stonewt::STONE) << endl;
    // wolfe.show_stn();
    cout << "The President weighed " << taft.set_mode(Stonewt::POUND) << endl;
    // taft.show_lbs();
    cout << "The total weighed " << incognito + wolfe + taft << endl;

    incognito = 276.8; // uses constructor for conversion
    taft = 325;        // same as taft = Stonewt(325)
    cout << "After dinner, the celebrity weighed " << incognito.set_mode(Stonewt::STONE) << endl;
    // incognito.show_stn();
    cout << "After dinner, the President weighed " << taft << endl;
    // taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    display(422, 2);
    cout << "No stone left unearned\n";
    return 0;
}

void display(const Stonewt &st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! " << st << std::endl;
    }
}