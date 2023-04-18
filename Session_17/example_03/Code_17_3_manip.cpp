// manip.cpp -- using format manipulators
#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter an integer: ";
    int n;
    cin >> n;

    cout << "n\tn*n\n";
    cout << n << "\t" << n * n << " (decimal)\n";

    // set to hex mode
    cout << hex;
    cout << n << "\t";
    cout << n * n << " (hexadecimal)\n";

    // set to octal mode
    cout << oct << n << "\t" << n * n << " (octal)\n";

    // alternative way to call a manipulator
    dec(cout);
    cout << n << "\t" << n * n << " (decimal)\n";

    return 0;
}