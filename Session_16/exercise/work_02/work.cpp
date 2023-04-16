#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void convertor(string &str);
bool fun(const string &str);

int main()
{
    string str;
    do
    {
        cout << "Enter a string(quit to quit): ";
        getline(cin, str);
        convertor(str);
        if (fun(str))
            cout << "Yes!\n";
        else
            cout << "No!\n";
    } while (str != "quit");
}

bool fun(const string &str)
{
    if (str.size() == 0)
        return false;
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

void convertor(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (!isalpha(ch))
            str.erase(i--, 1);
        else if (isupper(ch))
            str[i] = tolower(ch);
    }
}