#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int LCS(string A,string B){
    vector<vector<int>>t(A.size()+1,vector<int>(B.size()+1,0));

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
            
        }
    }
    return t[A.size()][B.size()];
}

//just call lcs on on A and reverse(A)
int LongestPalindromicSS(string A){
    string B=A;
    reverse(B.begin(),B.end());
    return LCS(A,B);
}

int main(){
    cout<<LongestPalindromicSS("agbcba");//op:5("abcba")
}