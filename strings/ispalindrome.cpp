/*
Write a recursive function is Palindrome accepts a string and
returns true if it reads the same forwards as backwards.
isPalindrome("madam") -> true
isPalindrome("racecar") ® true
isPalindrome("step on no pets") ® true
isPalindrome("able was I ere I saw elba") ® true
isPalindrome("Q") ® true
isPalindrome("Java") ® false
isPalindrome("rotater") ® false
isPalindrome("byebye") ® false
isPalindrome("notion") ® false
*/
#include<iostream>
using namespace std;

bool isPalindrome(string s)
{
    if(s.size()==0||s.size()==1)
        return true;
    else
    {
        if(s[0]==s[s.size()-1])
        {
            s.erase(s.begin(),s.begin()+1);
            s.pop_back();
            isPalindrome(s);
        }
        else
        return false;
    }
    
}

int main()
{
    string s;
    cout<<"enter the string"<<endl;
    cin>>s;
    bool a =isPalindrome(s);
    cout<<a;
}
