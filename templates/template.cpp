#include<iostream>
using namespace std;

template<typename T>

T maxx(T a,T b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int i = maxx(17,4);
    float f =maxx(12.23,12.24);
    string s =maxx("hello","hellp");
    cout<<i<<" "<<f<<" "<<s<<endl;
}