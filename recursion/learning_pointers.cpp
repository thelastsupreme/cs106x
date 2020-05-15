#include<iostream>
#include<vector>
using namespace std;

int check(int &num)
{
    if(num==150)
        return 0;
    
    num+=10;
    check(num);
}

int main()
{
    int a=100;
    cout<<a<<endl;;
    check(a);
    cout<<a;
}