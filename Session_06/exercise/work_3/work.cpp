//  编写一个菜单驱动程序的雏形。该程序显示一个提供四个选项的菜单——每个选项用一个字母标记
//  如果用户使用有效选项之外的字符进行响应，程序将提示。
#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "Please enter one of the following choices:" << endl
         << "c) carnivore\tp) painist\nt) tree \tg) game\n";
    while (cin.get(ch).get())
        switch (ch)
        {
        case 'c':
            cout << "A tiger is a carnivore.\n";
            return 0;
        case 'p':
            cout << "Beethoven is a painist.\n";
            return 0;
        case 't':
            cout << "A maple is a tree.\n";
            return 0;
        case 'g':
            cout << "Call of Duty is a game.\n";
            return 0;
        default:
            cout << "Please enter a c, p, t, or g: ";
            break;
        }

    return 0;
}