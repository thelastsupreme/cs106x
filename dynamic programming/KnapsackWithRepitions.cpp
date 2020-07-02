// Knapsack with repetitions problem
// Input: Weights w0, . . . ,wn−1 and values  v0, . . . , vn−1 of n items; total weight W
// (vi ’s, wi ’s, and W are non-negative integers).

// Output: The maximum value of items whose weight does not exceed W. 
//Each item can be used any number of times.
#include<iostream>
#include<vector>
using namespace std;

/************************************************
// value(u) = max i : (wi≤w){value(u − wi ) + vi}
*************************************************/

int knapsackDynamic(int W,vector<int>w,vector<int>v){ //weight and value vectors
    vector<int>temp(W+1);
    for (int u = 0; u <W+1; u++){
        for(int i=0;i<w.size();i++){
            if(w[i]<=u){
                temp[u]=max(temp[u],temp[u-w[i]]+v[i]);    //currweight-weight from array and add its value to urs
            }
        }
    }
    cout<<"constructed value array : |";
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" | ";
    }
    cout<<endl;
    return temp[W];
}
//pseudo code for recursive
/*
 T = dict ( )
def knapsack (w, v , u ) :
    if u not in T:
        T[ u ] = 0

for i in range ( len (w) ) :
    if w[ i ] <= u :
        T[ u ] = max(T[ u ] ,knapsack (w, v , u − w[ i ] ) + v [ i ] )
return T[ u ]
 */
int main(){
    int x=knapsackDynamic(10,{6,3,4,2},{30,14,16,9});
    cout<<"max profit is : "<<x; //48
}