//  block.cpp ------------- use a block statement
#include <iostream>
int main()
{
    using namespace std;
    cout << "The Amazing Account will sum and average ";
    cout << "five numbers for you.\n";
    cout << "Please enter five values:\n";
    double number;
    double sum = 0.0;
    for(int i = 1; i <= 5; i++)
    {                                                           // block starts here
        cout << "Vlaue " << i << ": ";
        cin >> number;
        sum += number;
    }                                                           // block ends here
    cout << "FIve exquisite choices indeed! ";
    cout << "They sum to " << sum << endl;
    cout << "and average to " << sum / 5 << ".\n";
    return 0;
}