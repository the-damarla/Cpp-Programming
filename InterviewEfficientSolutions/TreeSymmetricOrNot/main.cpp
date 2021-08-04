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
            temp->left = GetNode(data);
            return root;
        }
        if(temp->right != NULL)q.push(temp->right);
        else
        {
            temp->right = GetNode(data);
            return root;
        }
    }
    return root;
}

bool Symmetric(node* root1,node* root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 && root2 && root1->data == root2->data)
        return Symmetric(root1->left,root2->right) && Symmetric(root1->right,root2->left);
    return false;
}

int main()
{
    cout << "Enter \'0\' to stop giving input " << endl;
    node* root = NULL;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == 0)break;
        root = InsertNode(root,x);
    }
    if(Symmetric(root,root))cout << "Given tree is symmetric";
    else cout << "Given tree is not symmetric";
    return 0;
}
