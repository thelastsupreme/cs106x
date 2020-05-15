#include<iostream>
#include<string>
#include<vector>
#include"Employee.h"

class Lawyer : public Employee
{
private:
    int indexOfClient(string clientName);
    string lawSchool;
    vector<string>ClientNames;
public:
    Lawyer(string name,int yearsWorked,string lawSchool);
    void assignToClient(string ClientName);
    void unassignToClient(string ClientName);
    int getNumberOfClients();
};