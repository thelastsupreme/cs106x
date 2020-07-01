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
    vector<vector<int>>temp(b.size()+1,vector<int>(a.size()+1,0));
    for(int i=0;i<b.size()+1;i++){
        temp[i][0]=i;
    }
    for(int j=0;j<a.size()+1;j++){
        temp[0][j]=j;
    }
    int diff;
    for (int i = 1; i <b.size()+1; i++){
        for(int j=1;j<a.size()+1;j++){
            if(a[i-1]==b[j-1]){
                diff=0;
            }else{
                diff=1;
            }
            int x=min(temp[i-1][j]+1,temp[i][j-1]+1);
            temp[i][j]=min(x,temp[i-1][j-1]+diff);
        }
    }
   for(int i=0;i<b.size()+1;i++){
        for(int j=0;j<a.size()+1;j++){
            cout<<temp[i][j]<<"  ";
        }
        cout<<endl;
    }
    return temp[b.size()][a.size()];
}

int main(){
    int k=editDistance("editing","distance");
    cout<<"Cost is : "<<k;
}