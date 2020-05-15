//How would you modify diceSum so that it prints only unique
//combinations of dice, ignoring order?
#include<iostream>
#include<vector>
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
void dice_roll_helper(int n,int sum,int d_sum,vector<int>&A,int curr)
{
    if(n==0)
    {
       if(sumAll(A)==d_sum)
       {
           print(A);
           cout<<endl;
       }
    }
    else if(sum+1*n<=d_sum && sum+6*n>=d_sum)  //if the remaining elements are n min value they contribute is n and max is 6n
    {
        for(int i=curr;i<=6;i++)
        {
            A.push_back(i);
            dice_roll_helper(n-1,sum+i,d_sum,A,i);
            A.pop_back();
        }
    }
}

void dice_roll(int n,int sum,int d_sum)
{
    vector<int>chosen_values;
    dice_roll_helper(n,sum,d_sum,chosen_values,1);
}

int main()
{
    int n;
    int d_sum; //desired sum
    cout<<"enter a number"<<endl;
    cin>>n;
    cout<<"enter desired sum"<<endl;
    cin>>d_sum;
    dice_roll(n,0,d_sum);
}


