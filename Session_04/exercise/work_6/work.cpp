//  结构CandyBar包含3个成员，如编程练习5所示。
//  请编写一个程序，创建一个包含3个元素的CandyBar数组
//  并将它们初始化为所选择的值，然后显示每个结构的内容
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

    CandyBar arr[3] = {
        {"A", 2.4, 350},
        {"B", 2.3, 400},
        {"C", 4.5, 429}};

    for (int i = 0; i < 3; i++)
    {
        cout << "Brand: " << arr[i].brand << endl;
        cout << "Weight: " << arr[i].weight << endl;
        cout << "Calorie: " << arr[i].calorie << endl;
        cout << endl;
    }

    return 0;
}
