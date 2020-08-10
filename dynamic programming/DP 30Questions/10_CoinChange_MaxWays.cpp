#include<iostream>
#include<vector>
using namespace std;

//given c get the max no of ways you can split into these deonmination
//for given amount

int coinChange(vector<int>c,int value){
    vector<vector<int>>t(c.size()+1,vector<int>(value+1,0));

    for(int i=1;i<c.size()+1;i++){
        t[i][0]=1; //cause if u dont select any coins you can have a sum of 0
    }
    for(int i=1;i<c.size()+1;i++){
        for(int j=1;j<value+1;j++){
            if(c[i-1]<=j){
                t[i][j]=t[i][j-c[i-1]]+t[i-1][j]; //just add all possible ways
            }
            else{
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    return t[c.size()][value];
}
//using o(N) Memory
int coinchange2(vector<int> &A, int B) {
    int n = A.size();
    vector<int> dp(B+1, 0);
    dp[0]=1;
    
    for(int i=1; i<=n; i++){
        for(int j=A[i-1]; j<=B; j++)
            dp[j] += dp[j-A[i-1]];
    }
    
    return dp[B];
}

int main(){
    vector<int>denoms={50, 10 ,17 ,21 ,8 ,3, 12, 41 ,9 ,13 ,43, 37 ,49, 19 ,23 ,28, 45, 46 ,29, 16,34 ,25 ,2, 22, 1};
    cout<<coinChange(denoms,85)<<endl;
}