//  编写一个小程序， 要求以几英尺几英寸的方式输入其身高，并以磅为单位输入其体重。（使用三个变量来存储这些信息。）
//  该程序报告其BMI（Body Mass Index,体重指数）。
#include <iostream>
#include <cmath>
const int inch_per_feet = 12;
const double meter_per_inch = 0.0254;
const double pound_per_kg = 2.2;

int main()
{
    using namespace std;

    int height_feet;
    double height_inch;
    double height_meter;
    double weight_pound;
    double weight_kg;

    cout << "Enter your hetght\nfeet: ";
    cin >> height_feet;
    cout << "inch: ";
    cin >> height_inch;
    cout << "Enter your weight(pound): ";
    cin >> weight_pound;

    height_meter = (height_feet * inch_per_feet + height_inch) * meter_per_inch;
    weight_kg = weight_pound / pound_per_kg;

    cout << "Your BMI: " << weight_kg / pow(height_meter, 2) << endl;
    return 0;
}