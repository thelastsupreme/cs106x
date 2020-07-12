#include<iostream>
#include<vector>
#include<string>
using namespace std;

//merge both the strings such that the two strings are subsequences of the resulting string
//return min size of the resultant 
//ex: A:"geek" B:"eke" res:"geeke" op:5

//generate the size of longest common subsequence between two strings
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

int SCSS(string A,string B){
    //we just need to make sure the subsequence occurs only once in the resulting string
    //so its min len will be len(A)+len(B)-len(LCS(A,B))
    int lengthLCS=LCS(A,B);
    return A.length()+B.length()-lengthLCS;
}

int main(){
    cout<<SCSS("AGGTAB","GXTXAYB");//op 9:"AGXGTXAYB "
}