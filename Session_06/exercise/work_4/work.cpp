//  加入Benevolent Order of Programmer后，在BOP大会上
//  人们便可以通过加入者的真实姓名、头衔或秘密BOP姓名来了解他。
//  请编写一个程序，可以使用真实姓名、头衔、秘密姓名或成员偏好来列出成员。

#include <iostream>
static const int strsize = 80;
//  Benevolent Order of Programmers name structure
struct bop
{
    char fullname[strsize]; //  real name
    char title[strsize];    //  job title
    char bopname[strsize];  // secret BOP name
    int preference;         //  0 = fullname, 1 = title, 2 = bopname
};

using namespace std;

int main()
{
    bop members[3] = {
        {"WOOD", "Member", "Mr.W", 0},
        {"PIGEON", "Manager", "Mr.P", 1},
        {"MIKE", "Member", "Mr.M", 2}};
    cout << "Benevolent Order of Programmers Report" << endl
         << "a. display by name \t b.display by titile" << endl
         << "c. display by bopname \t d.display by preference" << endl
         << "q. quit" << endl;

    char ch;
    cout << "Enter your choice: ";
    while ((cin.get(ch).get()))
    {
        switch (ch)
        {
        case 'a':
            for (int i = 0; i < 3; i++)
                cout << members[i].fullname << endl;
            cout << "Next choice: ";
            break;
        case 'b':
            for (int i = 0; i < 3; i++)
                cout << members[i].title << endl;
            cout << "Next choice: ";
            break;
        case 'c':
            for (int i = 0; i < 3; i++)
                cout << members[i].bopname << endl;
            cout << "Next choice: ";
            break;
        case 'd':
            for (int i = 0; i < 3; i++)
            {
                if (members[i].preference == 0)
                    cout << members[i].fullname << endl;
                else if (members[i].preference == 1)
                    cout << members[i].title << endl;
                else if (members[i].preference == 2)
                    cout << members[i].bopname << endl;
            }
            cout << "Next choice: ";
            break;
        case 'q':
            cout << "Bye!\n";
            return 0;
        default:
            break;
        }
    }

    return 0;
}
