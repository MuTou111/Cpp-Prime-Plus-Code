#include "golf.h"
#include <iostream>

int main()
{
    golf g[4] = {};
    setgolf(g[0], "A", 1);
    showgolf(g[0]);
    for (int i = 0; setgolf(g[i]) && i < 4; i++)
    {
        std::cout << std::endl;
        showgolf(g[i]);
    }
    std:: cout << "Done\n";
    return 0;
}