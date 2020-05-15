#include<iostream>
#include<string>
using namespace std;

struct TrieNode 
{
    bool isWord;
    TrieNode* children[26]; // depends on the alphabet
};

void printAllWords(TrieNode* root) 
{
    printAllWordsHelper(root, "");
}

void printAllWordsHelper(TrieNode* root, string prefix) 
{
    if (root == nullptr)
    {
        return;
    }
    if (root->isWord) 
    {
        cout << prefix << endl;
    }
    for (int i = 0; i < 26; i++) 
    {
        printAllWordsHelper(root->children[i], prefix + char('a' + i));
    }
}

bool containsPrefix(TrieNode* node, string prefix)
{
    if (node == nullptr) 
    {
        return false;
    }   
    if (prefix.length() == 0) 
    {
        return true;
    }
    return containsPrefix(node->children[prefix[0] - 'a'],prefix.substr(1));
}