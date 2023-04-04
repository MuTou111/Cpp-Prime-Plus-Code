//  编写一个程序，要求用户输入驱车里程（公里）和使用汽油量（公升），然后指出汽车耗油量为一加仑的里程。
#include <iostream>

using namespace std;

int main()
{
    double milegae;
    double gasoline;
    cout << "Enter a number of mileage: ";
    cin >> milegae;
    cout << "Enter a number of gasoline: ";
    cin >> gasoline;
    cout << "Fulel consumption per hundred kilometers: "
         << gasoline / milegae * 100 << " L\n";
    return 0;
}