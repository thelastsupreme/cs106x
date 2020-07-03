// Edit distance
// Input: Two strings A[0 . . . n − 1] and
// B[0 . . .m − 1].
// Output: The minimal number of insertions,
// deletions, and substitutions needed to
// transform A to B. This number is known
// as edit distance or Levenshtein distance.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*******************************************************
ED(i,j)=min{ED(i,j-1)+1                 }
           {ED(i-1,j)+1                 }
           {ED(i-1,j-1)+diff(A[i],B[j]) }

////////////////////////////////////////////////////////

ED(i,j)=min{ ED(i , j − 1) + inscost(B[j ]),           }
           { ED(i − 1, j)  +  delcost(A[i ]),          }
           { ED(i − 1, j − 1) + substcost(A[i ], B[j ])}
********************************************************/
int editDistance(string a ,string b){
    vector<vector<int>>temp(a.size()+1,vector<int>(b.size()+1,0));
    for(int i=0;i<a.size()+1;i++){
        temp[i][0]=i;
    }
    for(int j=0;j<b.size()+1;j++){
        temp[0][j]=j;
    }
    int diff;
    for (int i = 1; i <a.size()+1; i++){
        for(int j=1;j<b.size()+1;j++){
            diff=(a[i-1]==b[j-1])?0:1;
            int x=min(temp[i-1][j]+1,temp[i][j-1]+1);
            temp[i][j]=min(x,temp[i-1][j-1]+diff);
        }
    }
   for(int i=0;i<a.size()+1;i++){
        for(int j=0;j<b.size()+1;j++){
            cout<<temp[i][j]<<"  ";
        }
        cout<<endl;
    }
    return temp[a.size()][b.size()];
}

int main(){
    int k=editDistance("aac","abac");
    cout<<"Cost is : "<<k;
}