#include<iostream>
#include<vector>
using namespace std;

//given an array count the number of subsets with given diff
//1.we know the sum of the subsets should be the overall range
//2.and difference is given so two linear equations solve for one subset sum
//3.call # ofsubset sum function on it

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

int main(){
    vector<int>A={1,1,2,3}; 
    cout<<subsetGivenDiff(A,1);
}