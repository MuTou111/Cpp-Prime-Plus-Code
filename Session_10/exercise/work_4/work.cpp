#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    double ar[] = {123.1};
    Sales s_1 = Sales(ar, 4), s_2;
    s_1.showSales();
    s_2.setSales();
    s_2.showSales();

    return 0;
}