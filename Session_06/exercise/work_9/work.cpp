//  从文件中读取完成编程练习6
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct Contributor
{
    char name[50];
    double money;
};

int main()
{
    ifstream inFiles;
    inFiles.open("work.txt");
    if (!inFiles.is_open())
    {
        cout << "Could not open the file." << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    int num;
    (inFiles >> num).get();
    Contributor *arr = new Contributor[num];
    for (int i = 0; i < num; i++)
    {
        inFiles.getline(arr[i].name, 50);
        (inFiles >> arr[i].money).get();
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
    inFiles.close();

    return 0;
}