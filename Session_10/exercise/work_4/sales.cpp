#include <iostream>
#include "sales.h"

namespace SALES
{
    using namespace std;
    Sales::Sales(const double ar[], int n)
    {
        double max = 0, min = 0, sum = 0;
        int i, len = sizeof(ar) / sizeof(double);
        for (i = 0; i < (n <= 4 ? n : 4); i++)
        {
            if (i < len)
            {
                this->sales[i] = ar[i];
                sum += this->sales[i];
            }
            else
                break;
        }

        while (i < 4)
            this->sales[i++] = 0;
        max = min = this->sales[0];
        for (int i = 1; i < 4; i++)
        {
            if (this->sales[i] > max)
                max = this->sales[i];
            if (this->sales[i] < min)
                min = this->sales[i];
        }
        this->max = max;
        this->min = min;
        this->average = sum / 4;
    }

    void Sales::setSales()
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            cout << "Enter #" << i + 1 << " sales: $";
            if (!(cin >> this->sales[i]))
            {
                cout << "Error! Input processe terminated." << endl;
                break;
            }
        }
        while (i < 4)
            this->sales[i++] = 0;

        double max, min, sum = 0;
        max = min = this->sales[0];
        for (int i = 1; i < 4; i++)
        {
            if (this->sales[i] > max)
                max = this->sales[i];
            if (this->sales[i] < min)
                min = this->sales[i];
            sum += this->sales[i];
        }
        this->max = max;
        this->min = min;
        this->average = sum / 4;
    }

    void Sales::showSales() const
    {
        for (int i = 0; i < 4; i++)
            cout << "#" << i + 1 << " sales: $" << this->sales[i] << endl;
        cout << "Max: " << this->max << endl
             << "Min: " << this->min << endl
             << "Average: " << this->average << endl;
    }
}