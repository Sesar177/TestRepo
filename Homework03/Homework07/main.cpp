#include "Employees.h"
#include <iostream>
#include <map>

using namespace std;

void display_employees(const map<string, int> &employees) //added reference to avoid copy
{
    for(const auto &info: employees)
    {
        cout << info.first << ": "
             << info.second << endl;
    }
}
void displayHighestSalaryEmp(const map<string, int> &employees)
{
    auto iter = employees.begin();
    int highestSalary = iter->second;
    string highestEmpName = iter->first;

    for(iter = employees.begin(); iter != employees.end(); iter++)
    {
        if(iter->second > highestSalary)
        {
            highestSalary = iter->second;
            highestEmpName = iter->first;
        }
    }
    cout << "Employee with the highest salary: " << highestEmpName <<" with " << highestSalary << endl;
}
void displayLowestSalaryEmp(const map<string, int> &employees)
{
    auto iter = employees.begin();
    int lowestSalary = iter->second;
    string lowestEmpName = iter->first;

    for(iter = employees.begin(); iter != employees.end(); iter++)
    {
        if(iter->second < lowestSalary)
        {
            lowestSalary = iter->second;
            lowestEmpName = iter->first;
        }
    }
    cout << "Employee with the lowest salary: " << lowestEmpName <<" with " << lowestSalary << endl;
}

int main()
{
    //Details 1.
    map<string, int> employees = {{"Alice", 50000},
                                    {"Bob", 45000},
                                    {"Charlie", 60000},
                                    {"David", 55000}};
    cout << "Initial employee map: " << endl;
    display_employees(employees);
    cout << endl;

    //Details 2.
    employees.emplace("Eve", 52000);
    employees.emplace("Frank", 48000);
    cout << "Employee map after adding Eve and Frank: " << endl;
    display_employees(employees);
    cout << endl;

    //Details 3.
    employees["Alice"] = 51000;
    cout << "Employee map after updating Alice's salary: " << endl;
    display_employees(employees);
    cout << endl;

    //Details 4.
    employees.erase("Charlie");
    cout << "Employee map after removing Charlie: " << endl;
    display_employees(employees);
    cout << endl;

    //Details 5.
    cout << "Is Bob in the employee map? ";
    if(employees.count("Bob"))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    //Details 6.
    display_employees(employees);
    cout<<endl;

    //Details 7.
    displayLowestSalaryEmp(employees);
    displayHighestSalaryEmp(employees);
}
