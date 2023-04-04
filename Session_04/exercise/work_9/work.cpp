//  完成编程练习6，但使用new来动态分配数组，而不是声明一个包含3个元素的CandyBar数组
#include <iostream>
#include <string>

struct CandyBar
{
    std::string brand;
    double weight;
    int calorie;
};

int main()
{
    using std::cout;
    using std::endl;
    
    CandyBar *arr = new CandyBar[3]{
        {"A", 2.4, 350},
        {"B", 2.3, 400},
        {"C", 4.5, 429}
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "Brand: " << arr[i].brand << endl;
        cout << "Weight: " << arr[i].weight << endl;
        cout << "Calorie: " << arr[i].calorie << endl;
        cout << endl;
    }

    delete []arr;

    return 0;
}