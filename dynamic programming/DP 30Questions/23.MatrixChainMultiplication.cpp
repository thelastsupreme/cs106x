#include<iostream>
#include<vector>
using namespace std;

//given an array and they represent the order of the matrices
//matrix 1 has an order of arr[0] X arr[1] matrix 2 has an order of arr[1] X arr[2] and so on
//return min cost of multiplication
#define MAXSIZE 50
vector<vector<int>>t(MAXSIZE,vector<int>(MAXSIZE,-1)); //2d matrix for memoization
int MCM(vector<int>&A,int i,int j){  //i starts from index 1
    if(i>=j){
        return 0;
    }
    if(t[i][j]!=-1)
        return t[i][j];
    int res=INT32_MAX;
    for(int k=i;k<=j-1;k++){  //from i to j-1 cause in order to not go out of bounds cause to extract order u need two blocks in the array
        int tempans=MCM(A,i,k)+MCM(A,k+1,j)+A[i-1]*A[k]*A[j]; //critical step and i-1 since i always starts one index ahead
        res=min(res,tempans);
    }
    return t[i][j]=res;  //store in mem matrix
}

int main(){
    vector<int>A={50,20,1,10,100};
    cout<<MCM(A,1,A.size()-1);
}