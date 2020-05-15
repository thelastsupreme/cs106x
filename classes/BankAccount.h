#include<string>
using namespace std;
class BankAccount
{
private:
    string name;
    double balance;
public:
    BankAccount(string AccountName,double startbalance);
    bool withdraw(double amount);
    bool deposit(double amount);
    double getBalance();
    void setName(string newName);
    void print_account();
};

