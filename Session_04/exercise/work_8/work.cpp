//  完成编程练习7，但使用new来为结构分配内存，而不是声明一个变量。
//  另外，让程序在请求输入比萨饼公司之前输入比萨饼的直径。
#include <iostream>
#include <string>

struct Pizza
{
    std::string company;
    double diameter;
    double weight;
};

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Pizza *pizza = new Pizza;
    cout << "Enter the diameter of pizza: ";
    cin >> pizza->diameter;
    cout << "Enter the company of pizza: ";
    cin.get();
    getline(cin, pizza->company);
    cout << "Enter the weight of pizza: ";
    cin >> pizza->weight;

    cout << "Here is the information of your pizza: \n"
         << "Company Name: " << pizza->company << endl
         << "Diameter: " << pizza->diameter << endl
         << "Weight: " << pizza->weight << endl;

    delete pizza;
    
    return 0;
}