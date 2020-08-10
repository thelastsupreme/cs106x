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
    
    /*critical step*/ 
    int temp=max(l,r)+A->val;       //here you are not cheking if your own value exceeds l+r+A->val
    int ans= l+r+A->val ;           // modified this step
    res=max(ans,res);
    return temp;
}

int maxPathSumLeaf(TreeNode* A) {
    int res=INT32_MIN;
    helper(A,res);
    return res;
}

int main(){
       /* Constructed binary tree is  
            1 
          /   \ 
        2      3 
      /  \      \
    7     5     -15
  */
  TreeNode *root = new TreeNode(1); 
  root->left        = new TreeNode(2); 
  root->right       = new TreeNode(3); 
  root->left->left  = new TreeNode(7); 
  root->left->right = new TreeNode(5);
  root->right->right= new TreeNode(-15);
  cout<<maxPathSumLeaf(root); //op 14  5->2->7
}