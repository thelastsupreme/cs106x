#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//partition a string into substrings such that each substring is a palindrome
//example: nitik -? n,iti,k
//return the minimum number of partitions to be made

#define MAXSIZE 50
vector<vector<int>>t(MAXSIZE,vector<int>(MAXSIZE,-1));

bool isPalindrome(string A,int i,int j){
    string T(A,i,j-i+1);
    string B=T;
    reverse(B.begin(),B.end());
    return(T==B);
}

//this question needs optimization beyond just using a global mem matrix
int PalindromePart(string &A,int i,int j){
    if(i>=j)
        return 0;
    if(isPalindrome(A,i,j))
        return 0;
    int res=INT32_MAX;
    //********code before optimization*****************
    // for(int k=i;k<=j-1;k++){
    //     int tempans=PalindromePart(A,i,k)+PalindromePart(A,k+1,j)+1; //+1 cause we just made a partition
    //     res=min(res,tempans);
    // }
    if(t[i][i]!=-1)
        return t[i][j];
    for(int k=i;k<=j-1;k++){
        int left=0,right=0;
        //the below if else ladder helps in further optimization
        //for parts of the recursive calls
        if(t[i][k]!=-1){
            left=t[i][k];
        }else{
            left=PalindromePart(A,i,k);
        }

        if(t[k+1][j]!=-1){
            right=t[k+1][j];
        }else{
            right=PalindromePart(A,k+1,j);
        }
        int tempans=left+right+1; //+1 cause we just made a partition
        res=min(res,tempans);
    }

    return t[i][j]=res;  //store in mem matrix
}

int main(){
    string s="nitik"; //op 2
    cout<<PalindromePart(s,0,s.size()-1);
}

