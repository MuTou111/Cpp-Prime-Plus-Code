#include "tv.h"

int main()
{
    Tv tv;
    Remote rm;
    rm.show_state();
    tv.changestate(rm);
    rm.onoff(tv);
    tv.changestate(rm);
    rm.show_state();
}