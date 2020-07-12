#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

// Below is one possible representation of A = “great”:


//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
 
// To scramble the string, we may choose any non-leaf node and swap its two children.

// For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that “rgeat” is a scrambled string of “great”.

// Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that “rgtae” is a scrambled string of “great”.



// Given two strings A and B of the same length, determine if B is a scrambled string of S.



// Input Format:

// The first argument of input contains a string A.
// The second argument of input contains a string B.
// Output Format:

// Return an integer, 0 or 1:
//     => 0 : False
//     => 1 : True
// Constraints:

// 1 <= len(A), len(B) <= 50
// Examples:

// Input 1:
//     A = "we"
//     B = "we"

// Output 1:
//     1

// Input 2:
//     A = "phqtrnilf"
//     B = "ilthnqrpf"
    
// Output 2:
//     0

unordered_map<string,bool>mp;
bool scramble(string A,string B){
    if(A==B){
        return true;
    }
    if(A.size()==0){
        return false;
    }
    string key=A+" "+B;
    if(mp.find(key)!=mp.end())
        return mp[key];
    bool res=false;

    for(int i=1;i<A.size();i++){ 
        //core logic is to once check after swap at k of string A till that index and one without swap
        bool cond1=(scramble(A.substr(0,i),B.substr(B.size()-i,i)))&&(scramble(A.substr(i,A.size()-i),B.substr(0,B.size()-i)));
        bool cond2=(scramble(A.substr(0,i),B.substr(0,i)))&&(scramble(A.substr(i,A.size()-i),B.substr(i,B.size()-i)));

        if(cond1||cond2){
            res=true;
            break;
        }
    }
    return mp[key]=res;
}

int main(){
    cout<<scramble("great","rgeat")<<endl;
    for(auto i:mp){
        cout<<i.first<<"->"<<i.second<<endl;
    }
}