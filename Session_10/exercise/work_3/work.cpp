#include "golf.h"
#include <iostream>

int main()
{
    golf g[4];
    g[0] = golf("B", 2);
    g[0].showgolf();
    for (int i = 0; i < 4; i++)
    {
        g[i].setgolf();
        std::cout << std::endl;
        g[i].showgolf();
    }
    std:: cout << "Done\n";
    return 0;
}