#include<iostream>
#include<vector>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i)<<" ";
	}
}
struct objects
{
    int weight;
    int value;
};

int knapsack(vector<objects>A,int capacity)
{

    if(A.size()==0||capacity==0)
    {
        return 0;   
    }
    objects b=A[A.size()-1];
    A.pop_back();
    int best=knapsack(A,capacity);
    if(b.weight<=capacity)
    {
        int with=b.value+knapsack(A,capacity-b.weight);
        best=max(best,with);
    }
    A.push_back(b);
    return best;  
}
int main()
{
    int n;
    cout<<"enter the number of objects"<<endl;
    cin>>n;
    vector<objects>A;
    cout<<"enter weights and then thier values"<<endl;
    int a,b,capacity;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cin>>b;
        objects c = {a,b};
        A.push_back(c);
    }
    /*
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cin>>b;
        A[i].weight=a;
        A[i].value =b;
    }
    */
   cout<<"enter capacity"<<endl;
   cin>>capacity;
   int result=knapsack(A,capacity);
   cout<<"profit is : "<<result<<endl;
   //cout<<"weight left is : "<<capacity<<endl;
}