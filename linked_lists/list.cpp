#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int data;
    ListNode* next;
};

/*ListNode* current=list;
while(current!=nullptr)
{
    cout<<current->data<<endl;
    current=current->next;
}
*/

//creating a list from a vector
ListNode *vectorToLinkedList(vector<int>v)
{
    if(v.size()==0)
        return nullptr;
    ListNode *head=new ListNode{v[0] ,nullptr};
    ListNode *currptr=head;
    for(int i=1;i<v.size();i++)
    {
        ListNode *node=new ListNode{v[i],nullptr};
        currptr->next=node;
        currptr=node;
    }
    return head;
}

//implementing size
int size(ListNode *front)
{
    ListNode* curr=front;
    int count=0;
    while(curr!=nullptr)
    {
        count++;
        curr=curr->next;
    }
    return count;
}
//print a list
void print(ListNode* front)
{
    if(front==nullptr)
        cout<<"empty"<<endl;
    else
    {
        ListNode* curr=front;
        while(curr!=nullptr)
        {
            cout<<curr->data<<" -> ";
            curr=curr->next;
        }
    }
    cout<<"null"<<endl;
}
//returns the value in the list at a given index
int get(ListNode* front,int index)
{
    ListNode *curr=front;
    for(int i=0;i<index;i++)
        curr=curr->next;
    return curr->data;
}
//appends a value to end the of the list
//reference to a pointer is passed so the changes occur in main fucntion as well
void add(ListNode*& front,int value)
{
    ListNode *newNode =new ListNode{value,nullptr};
    if(front==nullptr)
        front=newNode;
    else
    {
        ListNode *curr=front;
        while(curr->next!=nullptr)
            curr=curr->next;
        curr->next=newNode;
    }
        
}
//removes value at a given index from list
void remove(ListNode*& front,int index)
{
    if(index==0)
    {
        ListNode* nodeToDel=front;
        front=front->next;
        delete nodeToDel;
    }
    else
    {
        ListNode *curr=front;
        for(int i=0;i<index-1;i++)
            curr=curr->next;
        ListNode* nodeToDel=curr->next;
        curr->next=curr->next->next;
        delete nodeToDel;
    }
    
}
//insert the given value at the given index
void insert(ListNode *&front,int index,int value)
{
    if(index==0)
        front=new ListNode{value,front};
    else
    {
        ListNode *curr=front;
        for(int i=0;i<index-1;i++)
            curr=curr->next;
        ListNode *newNode =new ListNode{value,curr->next};
        curr->next=newNode;
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
    ListNode* A=vectorToLinkedList(v);
    print(A);
    insert(A,3,3123);
    remove(A,3);
    print(A);
    cout<<size(A);
}