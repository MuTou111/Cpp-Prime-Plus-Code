//  编写一个程序，记录捐助给“维护合法权利团体”的资金。该程序要求用户输入捐献者数目
//  然后要求用户输入每一个捐献者的姓名和款项。这些信息被存储存在一个动态分配的结构数组中
//  每个结构有两个成员：用来存储姓名的字符数组和用来存储款项的double成员。
//  程序将显示所有捐款超过10000的捐款者的姓名及其捐款数额。
#include <iostream>

struct Contributor
{
    char name[50];
    double money;
};

int main()
{
    using namespace std;
    int num;
    cout << "Number of contributor: ";
    (cin >> num).get();
    Contributor *arr = new Contributor[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter #" << i + 1 << " contributor's information:\n";
        cout << "Name: ";
        cin.getline(arr[i].name, 50);
        cout << "Money: ";
        (cin >> arr[i].money).get();
    }

    int count = 0;
    cout << "\n(Grand Patrons)\n";
    for (int i = 0; i < num; i++)
    {
        if (arr[i].money > 10000)
        {
            cout << arr[i].name << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "None.\n";

    count = 0;
    cout << "\n(Patrons)\n";
    for (int i = 0; i < num; i++)
    {
        if (arr[i].money <= 10000)
        {
            cout << arr[i].name << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "None.\n";

    delete[] arr;

    return 0;
}
