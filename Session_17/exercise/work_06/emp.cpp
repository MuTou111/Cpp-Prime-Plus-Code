#include "emp.h"

// abstr_emp methods
abstr_emp::abstr_emp() {}

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln, const std::string &j)
{
    fname = fn;
    lname = ln;
    job = j;
}

void abstr_emp::ShowAll() const
{
    using std::cout;
    using std::endl;
    cout << "First Name: " << fname << endl;
    cout << "Last Name: " << lname << endl;
    cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Enter the first name: ";
    getline(cin, fname);
    cout << "Enter the last name: ";
    getline(cin, lname);
    cout << "Enter the job: ";
    getline(cin, job);
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e)
{
    os << e.fname << ", " << e.lname << ", " << e.job;
    return os;
}

abstr_emp::~abstr_emp() {}

void abstr_emp::writeall(std::ofstream &fout)
{
    fout << fname << std::endl;
    fout << lname << std::endl;
    fout << job << std::endl;
}

// employee methods
employee::employee() {}

employee::employee(const std::string &fn, const std::string &ln, const std::string &j)
    : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void employee::writeall(std::ofstream &fout)
{
    fout << kind::Employee << std::endl;
    abstr_emp::writeall(fout);
}

// manager methods
manager::manager() {}

manager::manager(const std::string &fn, const std::string &ln,
                 const std::string &j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager &m) : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Employees: " << inchargeof << std::endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter the number of employees: ";
    std::cin >> inchargeof;
}

void manager::writeall(std::ofstream &fout)
{
    fout << kind::Manager << std::endl;
    abstr_emp::writeall(fout);
    fout << inchargeof << std::endl;
}

// fink methods
fink::fink() {}

fink::fink(const std::string &fn, const std::string &ln,
           const std::string &j, const std::string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const std::string &rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink &e) : abstr_emp(e)
{
    reportsto = e.reportsto;
}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Reportsto: " << reportsto << std::endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter the reportsto: ";
    getline(std::cin, reportsto);
}

void fink::writeall(std::ofstream &fout)
{
    fout << kind::Fink << std::endl;
    abstr_emp::writeall(fout);
    fout << reportsto << std::endl;
}

// highfink methods
highfink::highfink() {}

highfink::highfink(const std::string &fn, const std::string &ln,
                   const std::string &j, const std::string &rpo, int ico)
    : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico)
    : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager &m, const std::string &rpo)
    : abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Employees: " << InChargeOf() << std::endl;
    std::cout << "Reportsto: " << ReportsTo() << std::endl;
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter the number of Employees: ";
    std::cin >> InChangeOf();
    while (std::cin.get() != '\n')
        continue;
    std::cout << "Enter the reportsto: ";
    getline(std::cin, ReportsTo());
}

void highfink::writeall(std::ofstream &fout)
{
    fout << kind::Highfink << std::endl;
    abstr_emp::writeall(fout);
    fout << InChangeOf() << std::endl;
    fout << ReportsTo() << std::endl;
}