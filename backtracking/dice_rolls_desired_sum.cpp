//Write a function diceSum similar to diceRoll, but it also accepts
//a desired sum and prints only combinations that add up to exactly
//that sum.
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//function to calculate sum of elements in a vector
int sumAll(const vector<int>& v) {
    int sum = 0;
        for (int k : v) { sum += k; }
    return sum;
}
void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
void dice_roll_helper(int n,int sum,vector<int>&A)
{
    if(n==0)
    {
       if(sumAll(A)==sum)
       {
           print(A);
           cout<<endl;
       }
    }

    else
    {
        for(int i=1;i<=6;i++)
        {
            A.push_back(i);
            dice_roll_helper(n-1,sum,A);
            A.pop_back();
        }
    }
}

void dice_roll(int n,int sum)
{
    vector<int>chosen_values;
    dice_roll_helper(n,sum,chosen_values);
}

int main()
{
    int n;
    int sum;
    cout<<"enter a number"<<endl;
    cin>>n;
    cout<<"enter desired sum"<<endl;
    cin>>sum;
    dice_roll(n,sum);
}
