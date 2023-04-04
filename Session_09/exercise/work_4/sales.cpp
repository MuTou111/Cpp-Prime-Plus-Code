#include <iostream>
#include "sales.h"

namespace SALES
{
    using namespace std;
    void setSales(Sales &s, const double ar[], int n)
    {
        double max = 0, min = 0, sum = 0;
        int i, len = sizeof(ar) / sizeof(double);
        for (i = 0; i < (n <= 4 ? n : 4); i++)
        {
            if (i < len)
            {
                s.sales[i] = ar[i];
                sum += s.sales[i];
            }
            else
                break;
        }

        while (i < 4)
            s.sales[i++] = 0;
        max = min = s.sales[0];
        for (int i = 1; i < 4; i++)
        {
            if (s.sales[i] > max)
                max = s.sales[i];
            if (s.sales[i] < min)
                min = s.sales[i];
        }
        s.max = max;
        s.min = min;
        s.average = sum / 4;
    }

    void setSales(Sales &s)
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            cout << "Enter #" << i + 1 << " sales: $";
            if (!(cin >> s.sales[i]))
            {
                cout << "Error! Input processe terminated." << endl;
                break;
            }
        }
        while (i < 4)
            s.sales[i++] = 0;

        double max, min, sum = 0;
        max = min = s.sales[0];
        for (int i = 1; i < 4; i++)
        {
            if (s.sales[i] > max)
                max = s.sales[i];
            if (s.sales[i] < min)
                min = s.sales[i];
            sum += s.sales[i];
        }
        s.max = max;
        s.min = min;
        s.average = sum / 4;
    }

    void showSales(const Sales &s)
    {
        for (int i = 0; i < 4; i++)
            cout << "#" << i + 1 << " sales: $" << s.sales[i] << endl;
        cout << "Max: " << s.max << endl
             << "Min: " << s.min << endl
             << "Average: " << s.average << endl;
    }
}