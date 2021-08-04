#include <bits/stdc++.h>

using namespace std;

const int alp = 26;

struct TrieNode
{
    struct TrieNode *child[alp];
    bool isEnd;
    int isTot;
};

struct TrieNode *GetNode(void)
{
    struct TrieNode *newnode = new TrieNode;
    newnode->isEnd = false;
    for(int i=0;i<alp;i++)
    {
        newnode->child[i] = NULL;
    }
    newnode->isTot = 0;
    return newnode;
};

void insert(struct TrieNode *root,string s)
{
    int len = s.length();
    struct TrieNode *cur = root;
    for(int i=0;i<len;i++)
    {
        int index = s[i] - 'a';
        if(cur->child[index] == NULL)
            cur->child[index] = GetNode();
        cur = cur->child[index];
        cur->isTot += 1;
    }
    cur->isEnd = true;
}

bool Search(struct TrieNode *root,string s)
{
    int len = s.length();
    struct TrieNode *cur = root;
    for(int i=0;i<len;i++)
    {
        int index = s[i] - 'a';
        if(cur->child[index] == NULL)
            return false;
        cur = cur->child[index];
    }
    return cur->isEnd;
}


int SearchString(struct TrieNode *root,string s)
{
    int len = s.length();
    struct TrieNode *cur = root;
    for(int i=0;i<len;i++)
    {
        int index = s[i] - 'a';
        if(cur->child[index] == NULL)
            return 0;
        cur = cur->child[index];
    }
    if(cur == NULL)return 0;
    return cur->isTot;
}


int main()
{
    cout << "Enter \'STOP\' to stop giving input" << endl;
    struct TrieNode *root = GetNode();
    while(1)
    {
        cout << "Enter a string to insert : ";string s;cin >> s;
        if(s[0] == 'S')break;
        else insert(root,s);
    }
    cout << "Enter \'STOP\' to stop searching" << endl;
    while(1)
    {
        cout << "Enter data : ";string s;cin >> s;
        if(s[0] == 'S')break;
        else
        {
            if(Search(root,s))cout << "\nFound\n";
            else cout << "\nNot Found\n" ;
            cout << "Contacts with name " << s << " are : " << SearchString(root,s) << "\n";
        }
    }
    return 0;
}
