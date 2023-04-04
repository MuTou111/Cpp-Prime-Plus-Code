//  编写一个程序，它打开一个文本文件，逐个字符地读取该文件，直到到达文件尾，然后指出该文件中包含多少个字符。
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream Files;
    char filename[] = "work.txt";
    int count = 0;

    Files.open(filename);
    if (!Files.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    while (Files.get() && Files.good())
        count++;

    cout << count << " characters in the " << filename << endl;

    Files.close();

    return 0;
}