#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
    struct TrieNode *child[26];
    bool isEnd;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *newnode = new TrieNode;
    newnode->isEnd = false;
    for(int i=0;i<26;i++)
        newnode->child[i] = NULL;
    return newnode;
};

void insert(struct TrieNode *root,string s)
{
    struct TrieNode *cur = root;
    int len = s.length();
    for(int i=0;i<len;i++)
    {
        int index = s[i] - 'a';
        if(cur->child[index] == NULL)
            cur->child[index] = getNode();
        cur = cur->child[index];
    }
    cur->isEnd = true;
}

bool search(struct TrieNode *root,string s)
{
    struct TrieNode *cur = root;
    int len = s.length();
    for(int i=0;i<len;i++)
    {
        int index = s[i] - 'a';
        if(!cur->child[index])
            return false;
        cur = cur->child[index];
    }
    return cur->isEnd;
}

int main()
{
    cout << "Enter \'STOP\' to stop giving input\n";
    struct TrieNode *root = getNode();
    while(1)
    {
        cout << "Enter data : ";string s;cin >> s;
        if(s[0] == 'S')break;
        else insert(root,s);
    }
    cout << "now Search function\n";
    while(1)
    {
        cout << "Enter data : ";string s;cin >> s;
        if(s[0] == 'S')break;
        else
        {
            if(search(root,s))cout << "\nFound\n";
            else cout << "\nNOT FOUND\n";
        }
    }
    return 0;
}
