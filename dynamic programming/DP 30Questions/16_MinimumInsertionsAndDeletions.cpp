#include<iostream>
#include<vector>
#include<string>
using namespace std;

//minimum # of insertions and deletions to convert string A to string B

int LCS(string A,string B){
    vector<vector<int>>t(A.size()+1,vector<int>(B.size()+1,0));

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
            
        }
    }
    return t[A.size()][B.size()];
}
pair<int,int> countInsertionsAndDeletions(string A,string B){
    //insertions are len(B)-len(LCS)
    //deletions are len(A)-len(LCS)
    int lenLCS=LCS(A,B);
    int deletions=A.length()-lenLCS;
    int insertions=B.length()-lenLCS;

    return make_pair(insertions,deletions);
}

int main(){
    pair<int,int>A=countInsertionsAndDeletions("heap","pea");
    cout<<"insertions are : "<<A.first<<endl; 
    cout<<"deletions are : "<<A.second<<endl;

}