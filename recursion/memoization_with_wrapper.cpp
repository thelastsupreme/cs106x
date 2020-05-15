#include<iostream>
#include<unordered_map>
using namespace std;

int fibonacci(int i, unordered_map<int,int>& cache)
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

int fibonacci(int i)
{
    unordered_map<int,int>cache;
    return fibonacci(i,cache);
}



int main()
{
    int n;
    cout<<"enter a number "<<endl;
    cin>>n;
    int res=fibonacci(n);
    cout<<res;
}