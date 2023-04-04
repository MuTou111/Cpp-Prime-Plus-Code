#include <iostream>
#include "cow.h"

int main()
{
    Cow cow1, cow2;
    cow1.ShowCow();
    cow2 = Cow("WOOD", "Singing", 83.5);
    cow2.ShowCow();
    Cow cow3 = Cow(cow2);
    cow3.ShowCow();
    cow1 = cow2;
    cow1.ShowCow();

    return 0;
}