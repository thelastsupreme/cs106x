#include<iostream>
#include<vector>
using namespace std;

int UnBoundedKnapsack(vector<int>weights,vector<int>values,int capacity){
    vector<vector<int>>t(weights.size()+1,vector<int>(capacity+1,0));

    for(int i=1;i<weights.size()+1;i++){
        for(int j=1;j<capacity+1;j++){
            if(weights[i-1]<=j){
                t[i][j]=max(values[i-1]+t[i][j-weights[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    for(int i=0;i<weights.size()+1;i++){
        for(int j=0;j<capacity+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[weights.size()][capacity];
}

int main(){
    cout<<UnBoundedKnapsack({6,3,4,2},{30,14,16,9},10)<<endl;
}