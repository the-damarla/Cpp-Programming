#include <bits/stdc++.h>

using namespace std;
const int ALPHABET_SIZE = 26;
struct TrieNode
{
    struct TrieNode *child[ALPHABET_SIZE];
    bool isEnd;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->child[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *cur = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!cur->child[index])
            cur->child[index] = getNode();

        cur = cur->child[index];
    }

    // mark last node as leaf
    cur->isEnd = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->child[index])
            return false;

        pCrawl = pCrawl->child[index];
    }

    return (pCrawl->isEndOfWord);
}

int main()
{
    cout << "You are expected to insert the strings & then search for both operations to stop enter \'STOP\'" << endl;
    struct TrieNode *root = getNode();
    while(1)
    {
        string s;cout << "Enter a string : ";cin >> s;
        if(s[0] == 'S')break;
        else insert(root,s);
    }
    cout << "\n now you came to search  enter \'STOP\' to stop search\n";
    while(1)
    {
        string s;cout << "enter string : ";cin >> s;
        if(s[0] == 'S')break;
        else
        {
            if(search(root,s))cout << "\nFOUND\n";
            else cout << "\nNOTFOUND\n";
        }
    }
    return 0;
}
