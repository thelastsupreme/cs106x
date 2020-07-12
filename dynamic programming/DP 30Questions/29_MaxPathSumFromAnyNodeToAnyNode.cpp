// Given a binary tree T, find the maximum path sum.

// The path may start and end at any node in the tree.

// Input Format:

// The first and the only argument contains a pointer to the root of T, A.
// Output Format:

// Return an integer representing the maximum sum path.
// Constraints:

// 1 <= Number of Nodes <= 7e4
// -1000 <= Value of Node in T <= 1000
// Example :

// Input 1:

//        1
//       / \
//      2   3

// Output 1:
//      6

// Explanation 1:
//     The path with maximum sum is: 2 -> 1 -> 3

// Input 2:
    
//        -10
//        /  \
//      -20  -30

// Output 2:
//     -10

// Explanation 2
//     The path with maximum sum is: -10
#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode* A,int &res){
    if(A==nullptr)
        return 0;
    int l=helper(A->left,res);
    int r=helper(A->right,res);
    
    int temp=max(max(l,r)+A->val,A->val);
    int ans=max(temp,l+r+A->val);
    res=max(ans,res);
    return temp;
}

int maxPathSum(TreeNode* A) {
    int res=INT32_MIN;
    helper(A,res);
    return res;
}

int main(){
    /* Constructed binary tree is  
            1 
          /   \ 
        2      3 
      /  \ 
    4     5 
  */
  TreeNode *root = new TreeNode(1); 
  root->left        = new TreeNode(2); 
  root->right       = new TreeNode(3); 
  root->left->left  = new TreeNode(4); 
  root->left->right = new TreeNode(5); 
  cout<<maxPathSum(root); //op 11
}