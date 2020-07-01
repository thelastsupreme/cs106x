// Longest increasing subsequence
// Input: An array A = [a0, a1, . . . , an−1].
// Output: A longest increasing subsequence (LIS),
// i.e., ai1 , ai2 , . . . , aik such that
// i1 < i2 < . . . < ik , ai1 < ai2 < · · · < aik ,and k is maximal.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*****************************************************/
/* LIS(i ) = 1+max{LIS(j) : j < i and A[j ] < A[i ]}  */
/*****************************************************/

int lisDynamic(vector<int>A){
    vector<int>temp(A.size(),1);

    vector<int>prev(A.size(),-1); //using it just to print the sequence

    for(int i=1;i<temp.size();i++){
        for(int j=0;j<i;j++){
            if(A[j]<A[i]&& temp[i]<temp[j]+1)
            {
                temp[i]=temp[j]+1;
                prev[i]=j;
            }
        }
    }
    int res=INT32_MIN;
    for(int i=0;i<temp.size();i++){
        res=max(res,temp[i]);
    }

    /***
    //if u wanna generate sequence without prev then in temp array starting from our last element
    //find the first least element from it and store its index until u reach 0th index
    ***/

    //printing sequence using a prev vector
    int last=0;
    for( int i=1;i<A.size();i++){
        if(temp[i]>temp[last])
            last=i;
    }
    vector<int>list_index;
    int current=last;
    while(current>=0){
        list_index.push_back(current);
        current=prev[current];
    }
    reverse(list_index.begin(),list_index.end());
    cout<<"sequence is: "<<endl;
    for(int i=0;i<list_index.size();i++){
        cout<<A[list_index[i]]<<" ";
    }
    return res;
}


int lisRecursive(vector<int>&A,vector<int>&temp,int i){
    temp[i]=1;
    for (int j = 0; j < i; j++)
    {
        if(A[j]<A[i]){
            temp[i]=max(temp[i],lisRecursive(A,temp,j)+1);
        }
    }
    return temp[i];
}

int main(){
    vector<int>A={7,2,1,3,8,4,9,1,2,6,5,9,3,8,1};
    int x=lisDynamic(A);
    cout<<endl<<"length of sequence is : "<<x<<endl; //op 5

    //for recursive call
    vector<int>temp(A.size(),0);
    for(int k=0;k<A.size();k++)
        lisRecursive(A,temp,k);
    int res1=INT32_MIN;
    for(int i=0;i<temp.size();i++){
        res1=max(res1,temp[i]);
    }
    cout<<"recursive output : ";
    cout<<res1;
}