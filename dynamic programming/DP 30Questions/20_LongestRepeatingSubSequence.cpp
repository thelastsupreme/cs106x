#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//given a string return the length of longest subsequence which occurs more than once

//tricky logic : just do lcs of A with A but this time add a unique condition

int modifiedLCS(string A,string B){
    vector<vector<int>>t(A.size()+1,vector<int>(B.size()+1,0));

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1]&&(i!=j)){
                //i!=j is a condition which allows a subsequence which is repeating to occur by one less in resultant
                //cause we are removing the possibility when they occur at same indices 
                t[i][j]=1+t[i-1][j-1];
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
            
        }
    }
    return t[A.size()][B.size()];
}

int LRSS(string A){
    return modifiedLCS(A,A);
}

int main(){
    cout<<LRSS("AABEBCDD");//op is 3 (ABD)repeats twice
}