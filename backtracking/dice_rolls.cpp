//Write a recursive function diceRoll that accepts an integer
//representing a number of 6-sided dice to roll, and output all
//possible combinations of values that could appear on the dice.
#include<iostream>
#include<vector>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

void dice_roll_helper(int n,vector<int>&A)
{
    if(n==0)
       {
           print(A);
           cout<<endl;
       }
    else
    {
        for(int i=1;i<=6;i++)
        {
            A.push_back(i);
            dice_roll_helper(n-1,A);
            A.pop_back();
        }
    }
}

void dice_roll(int n)
{
    vector<int>chosen_values;
    dice_roll_helper(n,chosen_values);
}

int main()
{
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    dice_roll(n);
}
