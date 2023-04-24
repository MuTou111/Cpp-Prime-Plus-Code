#include "emp.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // for exit()

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1) // quit if no arguments
    {
        cerr << "Usage: " << argv[0] << " filename\n";
        exit(EXIT_FAILURE);
    }

    ofstream fout;
    ifstream fin; // open stream
    abstr_emp *data[10];
    int kind;

    fin.open(argv[1]); // connect stream to argv[file]
    fout.open(argv[1], ios_base::out | ios_base::app);
    if (!fin.is_open() && !fin.is_open())
    {
        cerr << "Could not open " << argv[1] << endl;
        fin.clear();
        exit(EXIT_FAILURE);
    }
    int i = 0;

    while (fin.good() && i < 10)
    {
        (fin >> kind).get();
        if (fin.good())
            switch (kind)
            {
            case Employee:
            {
                string fn, ln, j;
                getline(fin, fn);
                getline(fin, ln);
                getline(fin, j);
                data[i++] = new employee(fn, ln, j);
                break;
            }

            case Manager:
            {
                string fn, ln, j;
                int ico;
                getline(fin, fn);
                getline(fin, ln);
                getline(fin, j);
                (fin >> ico).get();
                data[i++] = (employee *)new manager(fn, ln, j, ico);
                break;
            }

            case Fink:
            {
                string fn, ln, j, rpo;
                getline(fin, fn);
                getline(fin, ln);
                getline(fin, j);
                getline(fin, rpo);
                data[i++] = (employee *)new fink(fn, ln, j, rpo);
                break;
            }

            case Highfink:
            {
                string fn, ln, j, rpo;
                int ico;
                getline(fin, fn);
                getline(fin, ln);
                getline(fin, j);
                getline(fin, rpo);
                (fin >> ico).get();
                data[i++] = (employee *)new highfink(fn, ln, j, rpo, ico);
                break;
            }
            }
    }

    for (int j = 0; j < i; j++)
    {
        data[j]->ShowAll();
        cout << endl;
    }

    while (i < 10)
    {
        cout << "Kind:\n0: Employee\t1: Manager\n2: Fink\t\t3: Hifhfink\n4: quit\n";
        (cin >> kind).get();
        if (kind == 4)
            break;

        switch (kind)
        {
        case Employee:
        {
            string fn, ln, j;
            cout << "Firstname: ";
            getline(cin, fn);
            cout << "Lastname: ";
            getline(cin, ln);
            cout << "Job: ";
            getline(cin, j);
            data[i] = new employee(fn, ln, j);
            data[i++]->writeall(fout);
            break;
        }

        case Manager:
        {
            string fn, ln, j;
            int ico;
            cout << "Firstname: ";
            getline(cin, fn);
            cout << "Lastname: ";
            getline(cin, ln);
            cout << "Job: ";
            getline(cin, j);
            cout << "Number of employees: ";
            (cin >> ico).get();
            data[i] = new manager(fn, ln, j, ico);
            ;
            data[i++]->writeall(fout);
            break;
        }

        case Fink:
        {
            string fn, ln, j, rpo;
            cout << "Firstname: ";
            getline(cin, fn);
            cout << "Lastname: ";
            getline(cin, ln);
            cout << "Job: ";
            getline(cin, j);
            cout << "Reportsto: ";
            getline(cin, rpo);
            data[i] = new fink(fn, ln, j, rpo);
            data[i++]->writeall(fout);
            break;
        }

        case Highfink:
        {
            string fn, ln, j, rpo;
            int ico;
            cout << "Firstname: ";
            getline(cin, fn);
            cout << "Lastname: ";
            getline(cin, ln);
            cout << "Job: ";
            getline(cin, j);
            cout << "Reportsto: ";
            getline(cin, rpo);
            cout << "Number of employees: ";
            (cin >> ico).get();
            data[i] = new highfink(fn, ln, j, rpo, ico);
            data[i++]->writeall(fout);
            break;
        }
        }
    }

    for (int j = 0; j < i; j++)
    {
        data[j]->ShowAll();
        cout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}