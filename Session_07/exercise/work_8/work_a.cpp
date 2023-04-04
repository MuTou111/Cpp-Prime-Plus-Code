//  在不使用array类的情况下完成程序清单7.15所做的工作。编写两个这样的版本：
//  a．使用const char *数组存储表示季度名称的字符串，并使用double数组存储开支。
//  b．使用const char *数组存储表示季度名称的字符串，并使用一个结构，
//  该结构只有一个成员——一个用于存储开支的double数组。
//  这种设计与使用array类的基本设计类似。
#include <iostream>
#include <array>
#include <string>
//  constant data
const int Season = 4;
const char *Snames[Season] = 
    {"Spring", "Summer", "Fall", "Winter"};

struct Expense{
    double expense[Season];
};

//  function that modify array object
void fill(double *, int);
//  function that uses array object without modifying it
void show(const double *, int);
//  function that modify array object
void fill(Expense *, int);
//  function that uses array object without modifying it
void show(const Expense *, int);

int main()
{
    std::cout << "Version a:\n";
    double expense[Season];
    fill(expense, Season);
    show(expense, Season);
    
    std::cout << "\nVersion b:\n";
    Expense st_expense = {};
    fill(&st_expense, Season);
    show(&st_expense, Season);
    return 0;
}

void fill (double *pa, int n)
{
    using namespace std;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa[i];
    }
}

void show(const double *da, int n)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i = 0; i < n; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

void fill (Expense *pa, int n)
{
    using namespace std;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa->expense[i];
    }
}

void show(const Expense *da, int n)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i = 0; i < n; i++)
    {
        cout << Snames[i] << ": $" << da->expense[i] << endl;
        total += da->expense[i];
    }
    cout << "Total Expenses: $" << total << endl;
}