// emp.h --- header file for abstr_emp class and children
#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>
#include <fstream>

enum kind
{
    Employee,
    Manager,
    Fink,
    Highfink
};


class abstr_emp
{
private:
    std::string fname; // abstr_emp's first name
    std::string lname; // abstr_emp's last name
    std::string job;

public:
    abstr_emp();
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &j);
    virtual void ShowAll() const; // labels and shows all data
    virtual void SetAll();        // prompts user for values
    friend std::ostream &operator<<(std::ostream &os, const abstr_emp &e);
    // just displays first and last name
    virtual ~abstr_emp() = 0; // virtual base class
    virtual void writeall(std::ofstream &fout);
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string &fn, const std::string &ln, const std::string &j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream &fout);
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof; // number of abstr_emps managed

protected:
    int InChargeOf() const { return inchargeof; } // output
    int &InChangeOf() { return inchargeof; }      // input

public:
    manager();
    manager(const std::string &fn, const std::string &ln,
            const std::string &j, int ico = 0);
    manager(const abstr_emp &e, int ico);
    manager(const manager &m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream &fout);
};

class fink : virtual public abstr_emp
{
private:
    std::string reportsto; // to whom fink reports

protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string &ReportsTo() { return reportsto; }

public:
    fink();
    fink(const std::string &fn, const std::string &ln,
         const std::string &j, const std::string &rpo);
    fink(const abstr_emp &e, const std::string &rpo);
    fink(const fink &e);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream &fout);
};

class highfink : public manager, public fink // management fink
{
public:
    highfink();
    highfink(const std::string &fn, const std::string &ln,
             const std::string &j, const std::string &rpo, int ico);
    highfink(const abstr_emp &e, const std::string &rpo, int ico);
    highfink(const fink &f, int ico);
    highfink(const manager &m, const std::string &rpo);
    highfink(const highfink &h);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream &fout);
};

#endif