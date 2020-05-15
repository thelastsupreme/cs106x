#include<iostream>
#include<vector>
using namespace std;

struct DlistNode
{
    int data;
    DlistNode * next;
    DlistNode * prev;
};

//creating a doubly linked list from a vector
DlistNode *vectorToDlinkedList(vector<int>v)
{
    if(v.size()==0)
        return nullptr;
    DlistNode *head=new DlistNode{v[0],nullptr,nullptr};
    DlistNode *curr=head;
    for(int i=1;i<v.size();i++)
    {
        DlistNode *node =new DlistNode{v[i],nullptr,nullptr};
        curr->next=node;
        node->prev=curr;
        curr=node;
    }
    return head;
}
//print dlinked list
void print(DlistNode* front)
{
    if(front==nullptr)
        cout<<"empty"<<endl;
    else
    {
        DlistNode* curr=front;
        while(curr!=nullptr)
        {
            cout<<curr->data<<" <-> ";
            curr=curr->next;
        }
    }
    cout<<"null"<<endl;
}
//implementing size
int size(DlistNode *front)
{
    DlistNode* curr=front;
    int count=0;
    while(curr!=nullptr)
    {
        count++;
        curr=curr->next;
    }
    return count;
}
//returns the value in the list at a given index
int get(DlistNode* front,int index)
{
    DlistNode *curr=front;
    for(int i=0;i<index;i++)
        curr=curr->next;
    return curr->data;
}
//appends a value to end the of the list
//reference to a pointer is passed so the changes occur in main fucntion as well
void add(DlistNode*& front,int value)
{
    DlistNode *newNode =new DlistNode{value,nullptr,nullptr};
    if(front==nullptr)
        front=newNode;
    else
    {
        DlistNode *curr=front;
        while(curr->next!=nullptr)
            curr=curr->next;
        curr->next=newNode;
        newNode->prev=curr;
    }
    
}

int main()
{
    int n;
    cout<<"enter the number of elements u want in the list"<<endl;
    cin>>n;
    vector<int>v;
    cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    DlistNode* A=vectorToDlinkedList(v);
    print(A);
    
}