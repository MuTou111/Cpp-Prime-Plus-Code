#include <iostream>
#include <string>
using namespace std;

bool fun(const string &str);

int main()
{
    string str;
    do
    {
        cout << "Enter a string(quit to quit): ";
        cin >> str;
        if (fun(str))
            cout << "Yes!\n";
        else
            cout << "No!\n";
    } while (str != "quit");
}

bool fun(const string &str)
{
    int i = 0, j = str.size() - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        else
        {
            i++, j--;
        }
    }
    return true;
}