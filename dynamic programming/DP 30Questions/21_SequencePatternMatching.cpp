#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//given two strings check if A is a subsequence of B

//just find LCS if its the same length as A return true

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

bool PatterMatch(string A,string B){
    int lenLCS=LCS(A,B);
    return(A.length()==lenLCS);
}
int main(){
    cout<<PatterMatch("AXY","ADXCPY"); //op 1
}