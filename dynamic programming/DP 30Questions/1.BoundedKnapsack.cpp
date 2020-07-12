#include<iostream>
#include<vector>
using namespace std;


int knapsack(vector<int>weights,vector<int>values,int capacity){
    vector<vector<int>>t(weights.size()+1,vector<int>(capacity+1,0));
    for(int i=1;i<weights.size()+1;i++){
        for(int j=1;j<capacity+1;j++){
            if(weights[i-1]<=j){
                t[i][j]=max(values[i-1]+t[i-1][j-weights[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    return t[weights.size()][capacity];
}

int main(){
    cout<<knapsack({4,5,1},{1,2,3},4)<<endl;
    cout<<knapsack({4,5,6},{1,2,3},3);
}