#include<iostream>
using namespace std;

// hashcode for now is just abs function
int hashCode(int a)
{
    return abs(a);
}

class hashing
{
private:
    struct HashNode
    {
        int data;
        HashNode* next;
        HashNode(int elem);
        HashNode(int newData, HashNode* newNext = nullptr)
        {
            data = newData;
            next = newNext;
        }
    };
public:
    int currsize;
    int capacity;
    HashNode** elems;
    hashing(int capacity);
    void add(int elem);
    bool contains(int elem);
    void remove(int elem);
    ~hashing();
};

hashing::hashing(int cap):capacity{cap},currsize{0}    //the new way of declaration learnt in udemy
{
    elems=new HashNode*[cap];
}

hashing::~hashing()
{
    delete[] elems;
}

bool hashing::contains(int elem)
{
    int index=hashCode(elem)%capacity;
    HashNode*curr=elems[index];
    while(curr!=nullptr)
    {
        if(curr->data==elem)
            return true;
        curr=curr->next;
    }
    return false;
}

void hashing::add(int elem)
{
    int index=hashCode(elem)%capacity;
    if(!contains(elem))
    {
        HashNode* newElem=new HashNode(elem,nullptr);
        newElem->next=elems[index];
        elems[index]=newElem;
        currsize++;
    }
}

void hashing::remove(int elem)
{
    int index=hashCode(elem)%capacity;
    HashNode*curr=elems[index];
    if(curr!=nullptr)
    {
        if(curr->data==elem)
        {
            elems[index]=curr->next;
            delete curr;
            currsize--;
        }
        else
        {
            while (curr->next!=nullptr)
            {
                if(curr->next->data==elem)
                {
                    HashNode* temp=curr->next;
                    curr->next=temp->next;
                    delete temp;
                    currsize--;
                    break;
                }
                curr=curr->next;
            }
            
        }
        
    }
}

int main()
{
    hashing test=hashing(10);
   // test.add(1);
    test.add(-2);
    test.add(12);
    test.add(7);
    test.add(27);
    test.add(-37);

    cout<<test.contains(1)<<endl;
    cout<<test.contains(4)<<endl;
}