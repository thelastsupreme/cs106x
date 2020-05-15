/*
Write a function nameDiamond that accepts a string parameter and
prints its letters in a "diamond" format as shown below.
– For example, nameDiamond("DAISY") should print:
D
DA
DAI
DAIS
DAISY
 AISY
  ISY
   SY
    Y
*/
/*
intercoversions c/c++ string
string("text") C string to C++ string
string.c_str() C++ string to C string
*/
//my code
#include<iostream>
using namespace std;

void nameDiamond(string s)
{
    string t="";
    for(int i=0;i<s.size();i++)
    {
        t+=s[i];
        cout<<t<<endl;
    }
    for(int i=0;i<s.size();i++)
    {
        t.erase(0,1);
        for(int j=0;j<s.size()-t.size();j++)
            cout<<" ";
        cout<<t<<endl;
    }
        
}

int main()
{
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    nameDiamond(s);

}
/*
//krutikas code
void nameDiamond(string s)
{
     for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<s[j];
        }
        cout<<endl;
    }
    int k=1;
    while(k<=4)
    {
        for(int j=1;j<=k;j++)
          cout<<" ";
        
        for(int j=k;j<=5;j++)
        {
            cout<<s[j];
        }
        cout<<endl;
        k++;
    }
}
*/