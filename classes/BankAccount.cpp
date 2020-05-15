#include<iostream>
#include<string>
#include<vector>
#include"BankAccount.h"
using namespace std;

BankAccount::BankAccount(string accountName,double startBalance)
{
    name=accountName;
    balance=startBalance;
}
//other way of writing using this
/*
BankAccount::BankAccount(string name,double balance)
{
    this->name=name;
    this->balance=balance;
}
*/

bool BankAccount::withdraw(double amount)
{
    if(amount<=balance && amount>=0)
    {
        balance-=amount;
        return true;
    }
    return false;
}

bool BankAccount::deposit(double amount)
{
    if(amount>=0)
    {
        balance+=amount;
        return true;
    }
    return false;
}
double BankAccount::getBalance()
{
    return balance;
}
void BankAccount::setName(string newName)
{
    name=newName;
}
void BankAccount::print_account()
{
    cout<<"name is :"<<name<<"     "<<"balance is"<<balance<<endl;
}
int main()
{
    int n;
    vector<BankAccount>v;
    cout<<"enter the number of accounts u want to create"<<endl;
    cin>>n;
    cout<<"enter name and then inital balance of the customer"<<endl;
    for(int i=0;i<n;i++)
    {
        string s;
        double d;
        cin>>s;
        cin>>d;
        v.push_back(BankAccount(s,d));
    }
    for(int i=0;i<n;i++)
        v[i].print_account();
}