//Write a recursive function printAllBinary that accepts an
//integer number of digits and prints all binary numbers that have
//exactly that many digits, in ascending order, one per line.
#include<iostream>
using namespace std;

void print_all_binary_helper(int n,string s="")
{
    if(n==0)
        cout<<s<<endl;
    else
    {
       print_all_binary_helper(n-1,s+"0");
       print_all_binary_helper(n-1,s+"1");
    }
}
void print_all_binary(int n)
{
    print_all_binary_helper(n);
}

int main()
{
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    print_all_binary(n);
}
