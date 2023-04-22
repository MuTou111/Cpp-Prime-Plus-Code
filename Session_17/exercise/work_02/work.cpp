#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    using namespace std;
    if (argc == 1) // quit if no arguments
    {
        cerr << "Usage: " << argv[0] << " filename\n";
        exit(EXIT_FAILURE);
    }
    ofstream fout(argv[1], ios_base::out | ios_base::app);
    if(!fout.is_open())
    {
        cerr << "Can't Open File!\n";
        exit(EXIT_FAILURE);
    }
    string temp;
    cout << "Enter the text (blank line to quit):\n";
    while(getline(cin, temp) && temp.size() > 0)
    {
        fout << temp << endl;
    }
    fout.close();

    return 0;
}