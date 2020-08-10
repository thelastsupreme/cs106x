#include<iostream>
#include<vector>
#include<string>
using namespace std;

//generate the size of longest common substring between two strings
int LCS(string A,string B){
    vector<vector<int>>t(A.size()+1,vector<int>(B.size()+1,0));

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }else{
                t[i][j]=0;
            }
            
        }
    }
    //just resturn max element in the t matrix
    int res=INT32_MIN;
    for(int i=0;i<A.size()+1;i++){
        for(int j=0;j<B.size()+1;j++){
           res=max(t[i][j],res);
        }
    }
    return res;
}

int main(){
    cout<<LCS("edcba","edcbaba"); //op:2("ab") 
}