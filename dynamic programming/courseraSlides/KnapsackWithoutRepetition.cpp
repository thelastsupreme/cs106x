// Knapsack without repetitions problem
// Input: Weights w0, . . . ,wn−1 and values v0, . . . , vn−1 of n items; total weight W
// (vi ’s, wi ’s, and W are non-negative integers).
// Output: The maximum value of items whose weight does not exceed W. Each item
// can be used at most once.

#include<iostream>
#include<vector>
using namespace std;

/***********************************************************
// value(u, i ) =max{value(u−wi−1, i−1)+vi−1, value(u, i−1)}
************************************************************/

int knapsackDynamic(int W,vector<int>w,vector<int>v){
    vector<vector<int>>temp(W+1,vector<int>(w.size()+1));     //no.of rows by W columns by w
    for (int  i = 0; i <W+1; i++){
        temp[i][0]=0;
    }
    for (int i = 1; i <w.size()+1; i++){
        for(int u=0;u<W+1;u++){
            temp[u][i]=temp[u][i-1];
            if(u>=w[i-1]){
                temp[u][i]=max(temp[u][i],temp[u-w[i-1]][i-1]+v[i-1]); //w[i-1] is either used or not
            }
        }
    }
    cout<<"constructed values matrix is: "<<endl;
    for(int u=0;u<W+1;u++){ 
        for(int i = 1; i <w.size()+1; i++){
            if(temp[u][i]%10==temp[u][i]) cout<<" "; //just a line to make the print look pretty cause of uneven spaces
            cout<<" "<<temp[u][i];
        }
        cout<<endl;
    }
    return temp[W][w.size()];
    
}

int main(){
    int x=knapsackDynamic(10,{6,3,4,2},{30,14,16,9});
    cout<<"max profit is : "<<x; 
}