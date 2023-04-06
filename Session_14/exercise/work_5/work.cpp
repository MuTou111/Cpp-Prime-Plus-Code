#include <iostream>
using namespace std;
#include "emp.h"

int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew"); //  recruitment?
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();
    return 0;
}

/*
Q：为什么没有定义赋值运算符？

A：各类的数据成员都拥有自己的赋值运算符函数，所以类默认的赋值运算符不会出现问题。

Q：为什么要将ShowAll()和SetAll()定义为虚？

A：方便动态联编选择合适的函数，如程序中使用基类指针调用函数时会更具对象选择函数。

Q：为什么要将abstr_emp定义为虚基类？

A：因为highfink引用了两个类，且这两个类都引用了abstr_emp基类，如果不定义为虚基类，
       highfink中将存在两个基类对象，从而出现二义性隐患。

Q：为什么highfink类没有数据部分？

A：因为所需数据都存在于基类中，可以从基类中继承数据成员。

Q：如果使用下面的代码替换程序的结尾部分，将会发生什么？
        abstr_emp tri[4] = {em, fi, hf, hf2};
        for(int i = 0; i < 4; i++)
            tri[i].ShowAll();

A：不允许使用abstr_emp数组，因为abstr_emp是抽象类，不可以被实例化。
*/