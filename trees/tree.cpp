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

bool contains(TreeNode *node,int num)
{
    if(node==nullptr)
        return false;
    else if(node->data==num)
        return true;
    else
    {
       /* contains(node->left,num);
        contains(node->right,num);
        return false;
        */
       return contains(node->left,num)||contains(node->right,num);
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

int main()
{
    TreeNode *root=new TreeNode(17,nullptr,nullptr);
    root->left=new TreeNode(41,nullptr,nullptr);
    root->right=new TreeNode(9,nullptr,nullptr);
    root->left->left=new TreeNode(29,nullptr,nullptr);
    root->left->right=new TreeNode(6,nullptr,nullptr);
    root->right->left=new TreeNode(81,nullptr,nullptr);
    root->right->right=new TreeNode(40,nullptr,nullptr);
    root->right->right->right=new TreeNode(121,nullptr,nullptr);
    cout<<"pre_order_print :"<<endl;
    print_preorder(root);
    cout<<"in_order_print :"<<endl;
    print_inorder(root);
    cout<<"post_order_print :"<<endl;
    print_postorder(root);
    cout<<"size of the tree is : ";
    cout<<size(root)<<endl;
    cout<<"height of the tree is : ";
    cout<<height(root)<<endl;
    cout<<contains(root,121)<<endl;
    cout<<contains(root,1111);
    deleteTree(root);

}