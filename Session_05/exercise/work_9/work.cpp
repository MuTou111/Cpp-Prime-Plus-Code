//  编写一个满足前一个练习中描述的程序，但使用string对象而不是字符数组。
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string word;
    int sum = 0;
    cout << "Enter words (to stop, type the word done): \n";
    while (cin >> word && word != "done")
        sum++;

    cout << "You entered a total of " << sum << " words.";
    return 0;
}