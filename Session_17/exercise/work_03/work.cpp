#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    using namespace std;
    if (argc < 3) // quit if no arguments
    {
        cerr << "Usage: " << argv[0] << " Sourcefilename Targetfilename2\n";
        exit(EXIT_FAILURE);
    }
    ifstream fin(argv[1]);
    if (!fin.is_open())
    {
        cerr << "Can't Open SourceFile!\n";
        exit(EXIT_FAILURE);
    }
    ofstream fout(argv[2]);
    if (!fout.is_open())
    {
        cerr << "Can't Open TargetFile!\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    while (fin.get(ch) && !fin.eof())
    {
        fout.put(ch);
    }
    fin.close();
    fout.close();
    cout << "Done!\n";
    return 0;
}