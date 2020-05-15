#include<iostream>
#include<string>
#include<vector>
#include"Employee.h"
using namespace std;

Employee::Employee(string name,int YearsWorked)
{
    this->name=name;
    this->YearsWorked=YearsWorked;
}

int Employee::getHoursWorkedPerWeek()
{
    return 40; //question requirement
}

string Employee::getName()
{
    return name;
}

int Employee::getYearsWoked()
{
    return YearsWorked;
}

Employee::~Employee()
{

}

