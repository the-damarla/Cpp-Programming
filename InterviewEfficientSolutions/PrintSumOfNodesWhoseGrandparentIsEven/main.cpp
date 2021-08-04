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

node* insertNode(node* root, int data)
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

void getSum(node* curr,node* p,node* gp,int &sum)
{
    if(curr == NULL)return;
    if(gp != NULL && gp->data % 2 == 0)
    {
        sum += curr->data;
        cout << curr->data << " -----> " << gp->data << "\n";
    }
    getSum(curr->left,curr,p,sum);
    getSum(curr->right,curr,p,sum);
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    node* root = NULL;
    while(1)
    {
        cout << "enter data : ";int x;cin >> x;
        if(x == 0)break;
        root = insertNode(root,x);
    }
    int sum = 0;
    cout << "Nodes having even numbered GranParent is : \n";
    getSum(root,NULL,NULL,sum);
    cout << "\nTheir sum is : " << sum;
    return 0;
}
