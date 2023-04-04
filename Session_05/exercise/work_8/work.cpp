//  编写一个程序，它使用一个char数组和循环来每次读取一个单词，直到用户输入done为止。
//  随后，该程序指出用户输入了多少个单词（不包括done）
#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    char word[200] = {};
    int sum = 0;
    cout << "Enter words (to stop, type the word done): \n";
    while (cin >> word && strcmp(word, "done"))
        sum++;

    cout << "You entered a total of " << sum << " words.";
    return 0;
}