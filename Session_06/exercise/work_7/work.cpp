//  编写一个程序，它每次读出一个单词，直到用户输入q。
//  然后，该程序指出有多少个单词以元音打头，有多少个单词以辅音打头
//  还有多少个单词不属于这两类。
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char Words[50];
    int Vowels = 0, Consonants = 0, Others = 0;
    cout << "Enter a word(q to quit): \n";
    while (cin.getline(Words, 50))
    {
        if (isalpha(Words[0]))
        {
            if (Words[0] == 'q')
                break;
            else if (Words[0] == 'a' || Words[0] == 'A' || Words[0] == 'e' || Words[0] == 'E' || Words[0] == 'i' || Words[0] == 'I' || Words[0] == 'o' || Words[0] == 'O' || Words[0] == 'u' || Words[0] == 'U')
                Vowels++;
            else
                Consonants++;
        }
        else
            Others++;
    }
    cout << Vowels << " words beginning with vowels" << endl;
    cout << Consonants << " words beginning with consonants" << endl;
    cout << Others << " others" << endl;

    return 0;
}