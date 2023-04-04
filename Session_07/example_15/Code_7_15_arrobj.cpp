//  arrobj.cpp ---------------------- functions with array objects (C++11)
#include <iostream>
#include <array>
#include <string>
//  constant data
const int Season = 4;
const std::array<std::string, Season> Snames = 
    {"Spring", "Summer", "Fall", "Winter"};

//  function that modify array object
void fill(std::array<double, Season> * pa);
//  function that uses array object without modifying it
void show(std::array<double, Season> da);

int main()
{
    std::array<double, Season> expense;
    fill(&expense);
    show(expense);
    return 0;
}

void fill (std::array<double, Season> * pa)
{
    using namespace std;
    for(int i = 0; i < Season; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show(std::array<double, Season> da)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i = 0; i < Season; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}