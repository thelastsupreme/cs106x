#include<iostream>
#include<vector>
using namespace std;

//given a rod of certain length cut into pieces
//values for certain lengths are given
//get max value

//unbounded knapsack model cause you can cut into pieces of same length more than once

int RodCutting(vector<int>lengths,vector<int>values,int lengthOfRod){
    vector<vector<int>>t(lengths.size()+1,vector<int>(lengthOfRod+1,0));

    for(int i=1;i<lengths.size()+1;i++){
        for(int j=1;j<lengthOfRod+1;j++){
            if(lengths[i-1]<=j){
                t[i][j]=max(values[i-1]+t[i][j-lengths[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
            
        }
    }

    return t[lengths.size()][lengthOfRod];
}

int main(){
    cout<<RodCutting({6,3,4,2},{30,14,16,9},10)<<endl;
}