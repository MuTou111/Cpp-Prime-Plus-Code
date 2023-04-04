//  CandyBar结构包含3个成员。
//  第一个成员存储candy bar的品牌名称；
//  第二个成员存储candy bar的重量（可能有小数）；
//  第三个成员存储candy bar的热量（整数）。
//  请编写一个程序，它使用一个这样的函数，
//  即将CandyBar的引用、char指针、double和int作为参数，并用最后3个值设置相应的结构成员。
//  最后3个参数的默认值分别为“Millennium Munch”、2.85和350。
//  另外，该程序还包含一个以CandyBar的引用为参数，并显示结构内容的函数。
//  请尽可能使用const。
#include <iostream>
#include <string>

struct CandyBar
{
    std::string brand;
    double weight;
    int calorie;
};

void set(CandyBar &, char * = "Millennium Munch", double = 2.85, int = 350);
void show(const CandyBar &);

int main()
{
    using namespace std;
    cout << "Enter the brand name: ";
    char brand[50] = {};
    cin.getline(brand, 50);
    cout << "Enter the weight: ";
    double weight = 0;
    cin >> weight;
    cout << "Enter the calorie: ";
    int calorie = 0;
    cin >> calorie;

    CandyBar candyBar = {};
    set(candyBar);
    show(candyBar);
    set(candyBar, brand, weight, calorie);
    show(candyBar);

    return 0;
}

void set(CandyBar &candyBar, char *brand, double weight, int calorie)
{
    candyBar.brand = brand;
    candyBar.weight = weight;
    candyBar.calorie = calorie;
}

void show(const CandyBar &candyBar)
{
    using namespace std;
    cout << "\nBrand: " << candyBar.brand << endl;
    cout << "Weight: " << candyBar.weight << endl;
    cout << "Calorie: " << candyBar.calorie << endl;
}