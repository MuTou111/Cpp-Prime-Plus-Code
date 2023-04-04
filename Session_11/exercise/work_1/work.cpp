#include <iostream>
#include <fstream>
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
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

        fstream file;
        file.open("result.txt");
        if (!file.is_open())
        {
            cout << "Can't open the file.\n";
            exit(EXIT_FAILURE);
        }
        file << "Target Distance: " << target << ", Step Size: " << dstep << endl;

        int count = 0;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            file << count << ": (x, y) = (" << step.xval() << ", " << step.yval() << ")" << endl;
            result = result + step;
            steps++;
            count++;
        }
        file << "After " << steps << " steps, the subject "
             << "has the following location:\n";
        file << result << endl;
        result.polar_mode();
        file << " or\n"
             << result << endl;
        file << "Average outward distance per step = "
             << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        file.close();
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}