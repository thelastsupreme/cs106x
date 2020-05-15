#include<iostream>
using namespace std;

void mystery(int& b, int c, int& a) 
{
    a++;
    b--;
    c += a; 
}
int main()
{ 
    int a = 5; 
    int b = 2;
    int c = 8;
    mystery(c, a, b);
    cout << a << " " << b << " " << c << endl;
    return 0;
}
// A. 5 2 8
// B. 5 3 7
// C. 6 1 8
// D. 6 1 13
// E. other
//Ans:B