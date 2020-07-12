#include<iostream>
#include<vector>
using namespace std;

//given an array assign + or - to each element and return the number of ways to return the target number

//1.so basically diving into two subsets and their diff should be target like Q6
int subsetCount(vector<int>A,int sum){
    vector<vector<int>>t(A.size()+1,vector<int>(sum+1,0));

    for(int i=0;i<A.size()+1;i++){
        t[i][0]=1; //since subset null can always genertate a sum zero
    }

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<sum+1;j++){
            if(A[i-1]<=j){
                t[i][j]=t[i-1][j]+t[i-1][j-A[i-1]];  

            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[A.size()][sum];
}
int subsetGivenDiff(vector<int>A,int Diff){
    int range=0;
    for(int i=0;i<A.size();i++){
        range+=A[i];
    }
    int s1=(range+Diff)/2;
    // cout<<s1<<endl;
    return subsetCount(A,s1);
}

int TargetSum(vector<int>A,int target){
    return subsetGivenDiff(A,target);
}

int main(){
    vector<int>A={1,1,2,3}; 
    cout<<TargetSum(A,1);
}