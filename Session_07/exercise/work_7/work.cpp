//  修改程序清单7.7中的3个数组处理函数，使之使用两个指针参数来表示区间。
//  fill_array( )函数不返回实际读取了多少个数字，而是返回一个指针，
//  该指针指向最后被填充的位置；其他的函数可以将该指针作为第二个参数，以标识数据结尾。
#include <iostream>
const int Max = 5;
//  function prototypes
double *fill_array(double *, int);
void show_array(const double *, const double *); //  don't change data
void revalue(double r, double *, double *);

int main()
{
    using namespace std;
    double properties[Max];

    double *tail = fill_array(properties, Max);
    show_array(properties, tail);
    if (properties < tail)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)) //  bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, tail);
        show_array(properties, tail);
    }
    cout << "Done.\n";
    cin.get();
    return 0;
}

double *fill_array(double *ar, int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin) //  bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0) //  signal to terminate
            break;
        ar[i] = temp;
    }
    return &ar[i - 1];
}

//  the following function can use, but not alter,
//  the array whose address is ar
void show_array(const double *head, const double *tail)
{
    using namespace std;
    for (int i = 0; head + i <= tail; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << head[i] << endl;
    }
}

//  mutiplies each element of ar[] by r
void revalue(double r, double *head, double *tail)
{
    for (int i = 0; head + i <= tail; i++)
        head[i] *= r;
}