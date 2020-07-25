#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//merge both the strings such that the two strings are subsequences of the resulting string
//return resultant 
//ex: A:"geek" B:"eke" res:"geeke" 

//logic here is to just use print lcs cause obviously the shortestCSS has lcs in it
//next just push additional characters in the else case where row and col value dont match
string SCSS(string A,string B){
    vector<vector<int>>t(A.size()+1,vector<int>(B.size()+1,0));

    //generate LCS t Matrix
    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
            
        }
    }
    //now iterate from the back and at a location check
    //if the char at that row index in A and char at that column index at B are equal
    //if yes then add them to result string
    //else go for the next location either top or left whichever has more value
    int i=A.size(),j=B.size();
    string res="";
    while (i>0&&j>0){
        if(A[i-1]==B[j-1]){
            res+=A[i-1];
            i--;                 
            j--;
        }else{             /******moidfication here ************/
            if(t[i-1][j]>t[i][j-1]){
                res+=A[i-1]; //push the greater element into the string
                i--;
            }else{
                res+=B[j-1];
                j--;
            }
        }
    }
    //additonal steps compared to lcs
    //iterate until we get 0 cause left over chars should be added cause those
    //are the unique characters that occured before lcs in respective strings
    while (i>0){
        res+=A[i-1];
        i--;
    }
    while (j>0){
        res+=B[j-1];
        j--;
    }
    
    reverse(res.begin(),res.end());
    return res;
    
}

int main(){
    cout<<SCSS("aabcc","GXTXAYB"); //op AGGXTXAYB
}