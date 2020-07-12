#include<iostream>
using namespace std;

//diameter is deifned as the longest path between any two nodes of a tree 
//it need not pass through the root of the tree 
//return the size of the path
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
    
    int temp=1+max(l,r);  //either add your node to the path and choose max side
    int ans=max(temp,l+r+1); //or check if your node and length and diameter from both sides is the max diameter
    res=max(ans,res);
    return temp;
}

int Diameter(TreeNode* A) {
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
  cout<<Diameter(root); //op 4
}