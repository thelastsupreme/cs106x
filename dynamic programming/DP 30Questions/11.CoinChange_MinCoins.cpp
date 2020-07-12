#include<iostream>
#include<vector>
using namespace std;

//given denominations get the min no of coins you can use tp split into these deonminations
//for given amount

int coinChange(vector<int>denominations,int value){
    vector<vector<int>>t(denominations.size()+1,vector<int>(value+1,0));

    for(int i=1;i<value+1;i++){
        //cause block 0,i represents no of coins needed whose denomination is 0
        //to get a sum of i
        //so infinity is represented as INTMAX
        t[0][i]=INT32_MAX-1; 
    }
    //special case where we need to initalize second row
    //the condition that needs to be checked here is
    //For Example:
    //if denoms were 3 5 2
    //then block 1,4 represents number of coins of denom 3 can be used to get a 4
    //which is impossible so init it with INT_MAX
    for(int i=1;i<value+1;i++){
        if(i%denominations[0]==0){
            t[1][i]=i/denominations[0];
        }else{
            t[1][i]=INT32_MAX-1;
        }
        
    }
    for(int i=1;i<denominations.size()+1;i++){
        for(int j=1;j<value+1;j++){
            if(denominations[i-1]<=j){
                t[i][j]=min(t[i][j-denominations[i-1]]+1,t[i-1][j]);
                //add one to current and take min of both
                //thats the reason we used INTMAX-1 cause there is going to be an increment by 1
                //while checking for min and it shouldnt overflow
            }
            else{
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    return t[denominations.size()][value];
}

int main(){
    cout<<coinChange({3,5,2},27);
}