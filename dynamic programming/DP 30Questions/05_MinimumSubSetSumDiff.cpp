#include<iostream>
#include<vector>
using namespace std;

//divide into two subsets such that the absolute diff of sums is minimum

//very unique approach
//1.get the total sum of the array(range)
//2.call the subsetsum function
//3.the last row of subset sum function will say what are the possible sums one could 
//generate from this array.
//4.extract all values of t
//5.pick the maximum and range-2*max_val is our answer 
//6.cause if s1 and s2 are two partitons then their sum is the range

bool subsetsum(vector<int>A,int sum,int &maxValue){ //maxValue stores the max sum possible within range/2
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
    //storing the possible values less than range/2 ao as to not generate repetitve combinations
    maxValue=INT32_MIN;
    for(int i=1;i<=sum/2;i++){
        if(t[A.size()][i]){
            maxValue=max(maxValue,i);
        }
    }
    return t[A.size()][sum];
}

int minSubsetDiff(vector<int>A){
    int range=0;
    for(int i=0;i<A.size();i++){
        range+=A[i];
    }
    // cout<<"range "<<range<<endl;
    int Maxvalue;
    subsetsum(A,range,Maxvalue);
    // cout<<Maxvalue<<endl;
    return range-2*Maxvalue;
}

int main(){
    vector<int>A={68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69, 48, 45 }; //op:4 cause {7},{1,2};
    cout<<minSubsetDiff(A);
}