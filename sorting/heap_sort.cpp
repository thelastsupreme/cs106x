#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<"\t";
}

void heapify(vector<int>&A,int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n&&A[left]>A[largest])
        largest=left;
    if(right<n&&A[right]>A[largest])
        largest=right;
    if(largest!=i)
    {
        swap(A[i],A[largest]);
        heapify(A,n,largest);
    }
}
void heap_sort(vector<int>&A)
{
    for(int i=A.size()/2-1;i>=0;i--)
        heapify(A,A.size(),i);

    for(int i=A.size()-1;i>0;i--)
    {
        swap(A[0],A[i]);

        heapify(A,i,0);
    }
}

int main()
{
    vector<int>A={2,5,3,1,6,4,7};
    heap_sort(A);
    print(A);
}