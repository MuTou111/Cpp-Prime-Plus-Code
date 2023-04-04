//  William Wingate从事比萨饼分析服务。对每个比萨饼，他都需要记录下列信息：
//  比萨饼公司的名称，可以有多个单词组成。
//  比萨饼的直径
//  比萨饼的重量
//  请设计一个能够存储这些信息的结构，并编写一个使用这种结构变量的程序。
//  程序将请求用户输入上述信息，然后显示这些信息。
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

    Pizza pizza;
    cout << "Enter the company of pizza: ";
    getline(cin, pizza.company);
    cout << "Enter the diameter of pizza: ";
    cin >> pizza.diameter;
    cout << "Enter the weight of pizza: ";
    cin >> pizza.weight;

    cout << "Here is the information of your pizza: \n"
         << "Company Name: " << pizza.company << endl
         << "Diameter: " << pizza.diameter << endl
         << "Weight: " << pizza.weight << endl;

    return 0;
}