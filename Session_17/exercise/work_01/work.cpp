#include <iostream>

int main()
{
    using namespace std;

    int count = 0;
    cout << "Enter: ";
    while(cin.peek() != '$')
    {
        cin.get();
        count++;
    }

    cout << "Total number of chars: " << count << endl;

    return 0;
}