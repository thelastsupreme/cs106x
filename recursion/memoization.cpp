#include<iostream>
#include<unordered_map>
using namespace std;

int fibonacci(int i, unordered_map<int, int>& cache)
{
    if (i < 2) 
    {
        return i;
    }
    else if (cache.find(i)!=cache.end())
    {
        return cache[i];
    }
    else
    {
        int result = fibonacci(i-1, cache) + fibonacci(i-2, cache);
        cache[i] = result;
        return result;
    }
}

int main()
{
    int n;
    cout<<"enter a number "<<endl;
    cin>>n;
    unordered_map<int,int> cache;
    int res=fibonacci(n,cache);
    cout<<res;
}