#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 4) // quit if no arguments
    {
        cerr << "Usage: " << argv[0] << " Sourcefilename1 Sourcefilename2 Targetfilename\n";
        exit(EXIT_FAILURE);
    }
    ifstream fin1(argv[1]);
    if (!fin1.is_open())
    {
        cerr << "Can't Open SourceFile1!\n";
        exit(EXIT_FAILURE);
    }
    ifstream fin2(argv[2]);
    if (!fin2.is_open())
    {
        cerr << "Can't Open SourceFile2!\n";
        exit(EXIT_FAILURE);
    }
    ofstream fout(argv[3]);
    if (!fout.is_open())
    {
        cerr << "Can't Open TargetFile!\n";
        exit(EXIT_FAILURE);
    }
    string temp1;
    string temp2;
    getline(fin1, temp1);
    getline(fin2, temp2);
    while (temp1.size() > 0 || temp2.size() > 0)
    {
        if(temp1.size() <= 0)
            fout << temp2 << endl;
        else if(temp2.size() <= 0)
            fout << temp1 << endl;
        else
            fout << temp1 << " " << temp2 << endl;
        temp1.clear();
        temp2.clear();
        getline(fin1, temp1);
        getline(fin2, temp2);
    }

    cout << "Done!\n";
    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}