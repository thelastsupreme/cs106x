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
    vector<int>temp(W+1,0);
    for (int u = 1; u <W+1; u++){
        for(int i=0;i<w.size()+1;i++){
            if(w[i]<=u){
                temp[u]=max(temp[u],temp[u-w[i]]+v[i]);    //currweight-weight from array and add its value to urs
            }
        }
    }
    // cout<<"constructed value array : |";
    // for(int i=0;i<temp.size();i++){
    //     cout<<temp[i]<<" | ";
    // }
    // cout<<endl;
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
    int x=knapsackDynamic(383,{96, 43, 28, 37, 92, 5, 3, 54, 93},{359, 963, 465, 706, 146, 282, 828, 962, 492});
    cout<<"max profit is : "<<x; //48
}