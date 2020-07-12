#include<iostream>
#include<vector>
using namespace std;

//return the # of subsets that have sum equal to given sum

int subsetCount(vector<int>A,int sum){
    vector<vector<int>>t(A.size()+1,vector<int>(sum+1,0));

    for(int i=0;i<A.size()+1;i++){
        t[i][0]=1; //since subset null can always genertate a sum zero
    }

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<sum+1;j++){
            if(A[i-1]<=j){
                //only change is to remove '||' and put a '+' from Q2 
                //cause obviously you are trying to store the no of ways
                //rather than checking if any ways will give me an answer
                t[i][j]=t[i-1][j]+t[i-1][j-A[i-1]];  

            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[A.size()][sum];
}

int main(){
    cout<<subsetCount({2,3,5,6,8,10},10); //op 3 {10},{2,8},{2,3,5}
}