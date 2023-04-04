#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    double x, y, a;
    for (y = 1.5; y > -1.5; y -= 0.1)
    {
        for (x = -1.5; x < 1.5; x += 0.05)
        {
            a = x * x + y * y - 1;
            cout.put(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
            usleep(300);
        }
        cout.put('\n');
    }
}