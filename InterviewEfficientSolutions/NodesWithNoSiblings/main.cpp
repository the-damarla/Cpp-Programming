#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* getNode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
};

node* insertNode(node* root,int data)
{
    if(root == NULL)
    {
        root = getNode(data);
        return root;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp->left != NULL)q.push(temp->left);
        else
        {
            temp->left = getNode(data);
            return root;
        }
        if(temp->right != NULL)q.push(temp->right);
        else
        {
            temp->right = getNode(data);
            return root;
        }
    }
    return root;
}

void NodesWithNoSiblings(node* root)
{
    if(root == NULL)return;
    if(root->left != NULL && root->right != NULL)
    {
        NodesWithNoSiblings(root->left);
        NodesWithNoSiblings(root->right);
    }
    else if(root->left != NULL)
    {
        cout << root->left->data << " ";
        NodesWithNoSiblings(root->right);
    }
    else if(root->left != NULL)
    {
        cout << root->right->data << " ";
        NodesWithNoSiblings(root->left);
    }
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    node* root = NULL;
    while(1)
    {
        int x;cout << "Enter data : ";cin >> x;
        if(x == 0)break;
        root = insertNode(root,x);
    }
    cout << "nodes with No Siblings are : ";NodesWithNoSiblings(root);
    return 0;
}
