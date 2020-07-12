#include<iostream>
#include<vector>
using namespace std;

int fibonacciRecursive(int n){
    if(n<=1){
        return n;
    }
    return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
}

int fibonacciDynamic(int n){
    vector<int>results(n+1);
    results[0]=0;
    results[1]=1;
    for(int i=2;i<results.size();i++){
        results[i]=results[i-1]+results[i-2];
    }
    return results[n];
}
//saves space
int fibonacciDynamicOptimized(int n){
    if(n<=1)
        return n;
    int curr=1,prev=0,new_curr;
    for(int i=0;i<n-1;i++){
        new_curr=prev+curr;
        prev=curr;
        curr=new_curr;
    }
    return curr;
}

int main(){
    cout<<fibonacciRecursive(10)<<endl;
    cout<<fibonacciDynamic(10)<<endl;
    cout<<fibonacciDynamicOptimized(10)<<endl;
}