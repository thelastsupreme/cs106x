#include<iostream>
#include<string>
using namespace std;

void mystery(string a, string& b) 
{
    a.erase(0, 1); // erase 1 from index 0
    b += a[0];
    b.insert(3, "FOO"); // insert at index 3
}

int main() 
{ 
    string a = "nick"; 
    string b = "troccoli"; 
    mystery(a, b); 
    cout << a << " " << b << endl;
    return 0;
}