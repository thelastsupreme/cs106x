#include<iostream>
#include<vector>
using namespace std;

//given denominations get the max no of ways you can split into these deonmination
//for given amount

int coinChange(vector<int>denominations,int value){
    vector<vector<int>>t(denominations.size()+1,vector<int>(value+1,0));

    for(int i=1;i<denominations.size()+1;i++){
        t[i][0]=1; //cause if u dont select any coins you can have a sum of 0
    }
    for(int i=1;i<denominations.size()+1;i++){
        for(int j=1;j<value+1;j++){
            if(denominations[i-1]<=j){
                t[i][j]=t[i][j-denominations[i-1]]+t[i-1][j]; //just add all possible ways
            }
            else{
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    return t[denominations.size()][value];
}

int main(){
    vector<int>denoms={25,10,5,1};
    cout<<coinChange(denoms,10)<<endl;
}