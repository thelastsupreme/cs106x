#include"HeadTA.h"
#include<string>

string HeadTA::getName()
{
    return "Head TA"+Employee::getName();   //adds HeadTA before returning name
}

int HeadTA::getHoursWorkedPerWeek()
{
    return Employee::getHoursWorkedPerWeek()/2; //HeadTA working hours are half as that of an employee
}