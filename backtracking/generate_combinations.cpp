//modified permutations code to generate combinations
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
void permute_helper(vector<string>&v,vector<string>perm)
{
    if(perm.size()==v.size()) //modification
    {
        print(perm);
        cout<<endl;
    }
    else
    {
        for(int i=0;i<v.size();i++)
        {
            string s=v[i];         //store string in s
            //v.erase(v.begin()+i);  //remove that from main vector
            perm.push_back(s);     //push it into temp vector
            permute_helper(v,perm);//recursive call on the changed vectors
            perm.pop_back();       //remove element from temp vector
           // v.insert(v.begin()+i,s);//insert element back in main vector
        }
    }
}
void permute(vector<string>A)
{
    vector<string>B;
    permute_helper(A,B);
}
int main()
{
    vector<string>A={"a", "b", "c", "d"};
    permute(A);
}

