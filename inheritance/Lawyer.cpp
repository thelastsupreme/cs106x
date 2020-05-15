#include<iostream>
#include<string>
#include"Lawyer.h"

//writing the constructor using constructor of Employee

Lawyer::Lawyer(string name,int yearsWorked,string lawSchool):Employee(name,yearsWorked)
{
    this->lawSchool=lawSchool;
}

void Lawyer::assignToClient(string clientName)
{
    ClientNames.push_back(clientName);
}

int Lawyer::getNumberOfClients()
{
    return ClientNames.size();
}

int Lawyer::indexOfClient(string clientName)
{
    for(int i=0;i<ClientNames.size();i++)
    {
        if(ClientNames[i]==clientName)
            return i;
    }
    return -1;
}

void Lawyer::unassignToClient(string clientName)
{
    int index=indexOfClient(clientName);
    if(index>=0)
    {
        ClientNames.erase(ClientNames.begin()+index);
    }
}