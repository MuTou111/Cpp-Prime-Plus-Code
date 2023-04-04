#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    Sales s_1, s_2;
    double ar[] = {123.1};
    setSales(s_1, ar, 4);
    showSales(s_1);
    setSales(s_2);
    showSales(s_2);

    return 0;
}