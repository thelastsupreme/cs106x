#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Employee
{
private:
    string name;
    int YearsWorked;
public:
    Employee(string name,int yearsWorked);
    int getHoursWorkedPerWeek();
    virtual string getName();  //declared as virtual cause it is being overrriden in HeadTA
    int getYearsWoked();
    ~Employee();
};
