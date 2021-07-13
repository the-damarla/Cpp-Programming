#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* GetNode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
};

node* InsertNode(node* root,int data)
{
    if(root == NULL)
    {
        root = GetNode(data);
    }
    else if(data <= root->data)
    {
        root->left = InsertNode(root->left,data);
    }
    else
        root->right = InsertNode(root->right,data);
    return root;
};

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    node* root = NULL;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == 0)break;
        root = InsertNode(root,x);
    }
    return 0;
}
