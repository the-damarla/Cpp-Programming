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
    node* temp = root;
    queue<node*> q;
    q.push(temp);
    while(!q.empty())
    {
        node* x = q.front();
        q.pop();
        if(x->left != NULL)q.push(x->left);
        else
        {
            x->left = GetNode(data);
            return root;
        }
        if(x->right != NULL)q.push(x->right);
        else
        {
            x->right = GetNode(data);
            return root;
        }
    }
    return root;
};

void DFS(node* root,int sum,vector<int> pathSum,vector<vector<int>> &wholesum)
{
    if(root == NULL)return;
    //sum += root->data;
    pathSum.push_back(root->data);
    if(root->left == NULL && root->right == NULL)
    {
        wholesum.push_back(pathSum);
        return;
    }
    DFS(root->left,sum,pathSum,wholesum);
    DFS(root->right,sum,pathSum,wholesum);
}

void PathSum(node* root)
{
    vector<int> pathSum;
    vector<vector<int>> wholesum;
    DFS(root,0,pathSum,wholesum);
    cout << "The paths available : [";
    for(auto x:wholesum)
    {
        cout << "[";
        for(int i=0;i<x.size()-1;i++)cout << x[i] << "->";
        cout << x[x.size()-1] << "]";
    }
    cout << "]";
    return;
}

bool CheckSum(node* root,int sum)
{
    bool ans = 0;
    if(root == NULL)return false;
    int subsum = sum - root->data;
    if(subsum == 0 && root->left == NULL && root->right == NULL)return true;
    if(root->left)ans = ans || CheckSum(root->left,subsum);
    if(root->right)ans = ans || CheckSum(root->right,subsum);
    return ans;
}

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
    PathSum(root);
    cout << "\nEnter a sum : ";int sum;cin >> sum;
    if(CheckSum(root,sum))cout << "\nYes, There is a path";
    else cout << "\nNo path is found";
    return 0;
}
