#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <iostream>

class Employees
{
private:
    std::string name;
    int salary;
public:
    Employees(): name(" "),salary(0)
    { }
    Employees(std::string n, int s): name(n),salary(s)
    { }
};
#endif // EMPLOYEES_H
