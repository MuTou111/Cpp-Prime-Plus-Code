#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void ShowStr(string &temp);

class Store
{
private:
    ofstream &fout;

public:
    Store(ofstream &fout) : fout(fout) {}
    void operator()(string &str);
};

void Store::operator()(string &str)
{
    fout.write(str.c_str(), int(str.size()) + 1);
}

void GetStrs(ifstream &fin, vector<string> &vistr);

main()
{
    vector<string> vostr;
    string temp;

    // acquire strings
    cout << "Enter string (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(string &temp)
{
    cout << "Contents: ";
    cout << temp << endl;
}

void GetStrs(ifstream &fin, vector<string> &vistr)
{
    while (!fin.eof())
    {
        string temp;
        char buffer;
        while (fin.read(&buffer, sizeof(buffer)) && buffer != '\0')
        {
            temp.push_back(buffer);
        }
        temp.append(&buffer);
        if (temp.size() > 0)
            vistr.push_back(temp);
        temp.clear();
    }
}