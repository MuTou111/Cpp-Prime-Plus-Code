#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream fin("Source1.txt");
    string temp;
    while (getline(fin, temp))
    {
        cout << temp;
        if (fin.good())
            cout << "Good!";
    }

    return 0;
}