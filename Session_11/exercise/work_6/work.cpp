#include "stonewt.h"
#include <iostream>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    Stonewt st[6] = {900, 100, 200};
    double pounds;
    for (int i = 3; i < 6; i++)
    {
        cout << "Enter the pounds: ";
        if (!(cin >> pounds))
        {
            cout << "Bad input, Try again.\n";
            i--;
            continue;
        }
        st[i] = pounds;
    }
    Stonewt max;
    Stonewt min;
    int count = 0;
    max = min = st[0];
    Stonewt stand(11, 0);
    for (int i = 1; i < 6; i++)
    {
        if (st[i] > max)
            max = st[i];
        if (st[i] < min)
            min = st[i];
        if (st[i] >= stand)
            count++;
    }
    cout << "Max: " << endl;
    max.show_stn();
    cout << "Min: " << endl;
    min.show_stn();
    cout << "Count: " << count << endl;

    return 0;
}