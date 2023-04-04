#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime>
#include "vect.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0)); //  seed rand-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    double max = 0;
    double min;
    double sum = 0;
    double average = 0;
    int time;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        cout << "Enter time: ";
        if (!(cin >> time))
            break;
        for (int i = 0; i < time; i++)
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            if(i == 0)
            {
                max = steps;
                min = steps;
            }
            else
            {
                if(steps > max)
                    max = steps;
                if(steps < min)
                    min = steps;
            }
            sum += steps;
            steps = 0;
            result.reset(0.0, 0.0);
        }
        average = sum / time;
        cout << "Max: " << max << endl;
        cout << "Min: " << min << endl;
        cout << "Average: " << average << endl;
        max = 0;
        average = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}