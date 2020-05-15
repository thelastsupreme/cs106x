#include<iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data,TreeNode* left,TreeNode* right)
    {
        this->data=data;
        this->left=left;
        this->right=right;
    }
    bool isLeaf()
    {
        return left==nullptr&&right==nullptr;
    }
};

//print function recursive
void print_preorder(TreeNode* node)
{
    if(node!=nullptr)
    {
        cout<<node->data<<endl;
        print_preorder(node->left);
        print_preorder(node->right);
    }
}

void print_inorder(TreeNode* node)
{
    if(node!=nullptr)
    {
        print_inorder(node->left);
        cout<<node->data<<endl;
        print_inorder(node->right);
    }
}

void print_postorder(TreeNode* node)
{
    if(node!=nullptr)
    {
        print_postorder(node->left);
        print_postorder(node->right);
        cout<<node->data<<endl;
    }
}

int size(TreeNode *node)
{
    if(node==nullptr)
        return 0;
    else
    {
        return 1+size(node->left)+size(node->right);
    }
}
//contains is bit different from normal tree search
bool contains(TreeNode *node,int num)
{
    if(node==nullptr)
        return false;
    else if(node->data==num)
        return true;
    else if(node->data>num)
        return contains(node->left,num);
    else
        return contains(node->right,num);
}
int getMin(TreeNode *node)
{
    if(node->left==nullptr)
        return node->data;
    else
        return getMin(node->left);
    
}

int getMax(TreeNode *node)
{
    if(node->right==nullptr)
        return node->data;
    else
        return getMax(node->right);
    
}

void add(TreeNode* &node,int value)
{
    if(node==nullptr)
        node=new TreeNode(value,nullptr,nullptr);
    else if(node->data>value)
        add(node->left,value);
    else
        add(node->right,value);
    
}
void remove(TreeNode* &node,int value)
{
    if(node->left==nullptr&&node->right==nullptr)
        delete node;
    else if(node->left==nullptr&&node->right!=nullptr)
    {
        int a=getMin(node->right);
        remove(node->right,a);
        node->data=a;
    }
    else if(node->left!=nullptr&&node->right==nullptr)
    {
        int a=getMax(node->left);
        remove(node->left,a);
        node->data=a;
    }
    else
    {
        //either get min from right subtree or max from left subtree
        int a =getMin(node->right);
        remove(node->right,a);
        node->data=a;
    }
    
}
int height(TreeNode *node)
{
    if(node==nullptr)
        return 0;
    else
    {
        int a=height(node->left);
        int b=height(node->right);
        return(1+max(a,b));
    }
    
}
void deleteTree(TreeNode *node)
{
    if(node==nullptr)
        return;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}
