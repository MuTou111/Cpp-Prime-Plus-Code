//  下面是一个结构声明：
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
//  a．编写一个函数，按值传递box结构，并显示每个成员的值。
//  b．编写一个函数，传递box结构的地址，并将volume成员设置为其他三维长度的乘积。
//  c．编写一个使用这两个函数的简单程序。
#include <iostream>

void show(box var);
void set_volume(box *var);

using namespace std;

int main()
{
    box var = {
        "A", 10, 30, 40};
    set_volume(&var);
    show(var);

    return 0;
}

void show(box var)
{
    cout << "Maker: " << var.maker << endl
         << "Height: " << var.height << endl
         << "Width: " << var.width << endl
         << "Length: " << var.length << endl
         << "Volume: " << var.volume << endl;
}

void set_volume(box *var)
{
    var->volume = var->height * var->length * var->width;
}