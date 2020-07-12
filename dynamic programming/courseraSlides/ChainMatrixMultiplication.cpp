// Chain matrix multiplication
// Input: Chain of n matrices A0, . . . , An−1 to be
// multiplied.
// Output: An order of multiplication minimizing the
// total cost of multiplication.

// The cost of multiplying two matrices of size
// p × q and q × r is pqr

/*****************************************************
// M(i , j) = min(i<k<j){M(i,k)+M(k+1,j)+mi-1 ·mk ·mj}
******************************************************/
//Base case:M(i,i+1)=0
#include<iostream>
#include<vector>
using namespace std;

int matrix_mult(vector<int>m){
    vector<vector<int>>temp(m.size()+1,vector<int>(m.size()+1,INT32_MAX));

    for(int i=1;i<temp.size();i++) temp[i][i]=0;

    for(int s=2;s<temp.size();s++){
        for(int i=1;i<temp.size()-s+1;i++){
            int j=i+s-1;
            for(int k=i;k<j;k++){
                temp[i][j]=min(temp[i][j],temp[i][k]+temp[k+1][j]+m[i-1]*m[k]*m[j]);
            }
        }
    }
    for (int i = 0; i <temp.size(); i++)
    {
        for (int  j = 0; j < temp.size(); j++)
        {
            cout<<temp[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    return temp[1][temp.size()-2];
}

int main(){
    cout<<matrix_mult({50,20,1,10,100})<<endl;
}
