#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << ' ';
	}
}
void permute_helper(vector<string>&v,int curr)
{
    if(curr>=v.size())
    {
        print(v);
        cout<<endl;
    }
    else
    {
        for(int i=curr;i<v.size();i++)
        {
                 
            swap(v[curr], v[i]);
            permute_helper(v,i+1);
            swap(v[curr], v[i]);  
        }
    }
}
void permute(vector<string>A)
{
    vector<string>B;
    permute_helper(A,0);
}

int main()
{
    vector<string>A={"a", "b", "c"};
    permute(A);
}
