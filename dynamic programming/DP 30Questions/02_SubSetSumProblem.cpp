#include<iostream>
#include<vector>
using namespace std;

//does a subset exist whose sum of elements is the given sum

bool subsetsum(vector<int>A,int sum){
    vector<vector<bool>>t(A.size()+1,vector<bool>(sum+1,false));

    for(int i=0;i<A.size()+1;i++){
        t[i][0]=true; //since subset null can always genertate a sum zero
    }

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<sum+1;j++){
            if(A[i-1]<=j){
                t[i][j]=t[i-1][j]||t[i-1][j-A[i-1]];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    // for(int i=0;i<A.size()+1;i++){
    //     for(int j=0;j<sum+1;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return t[A.size()][sum];
}

int main(){
    cout<<subsetsum({3, 34, 4, 12, 5, 2},9);
}