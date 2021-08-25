#include <bits/stdc++.h>

using namespace std;

int sum = 0;

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

int MaxHeight(node* root)
{
    if(root == NULL)return 0;
    return 1+max(MaxHeight(root->left),MaxHeight(root->right));
}

void PrintLevel(node* root,int level)
{
    if(root == NULL)return;
    if(level == 1)cout << root->data << " ";
    else if(level > 1)
    {
        PrintLevel(root->left,level-1);
        PrintLevel(root->right,level-1);
    }
}

void LevelPrint(node* root)
{
    int h = MaxHeight(root);
    for(int i=1;i<=h;i++)
        PrintLevel(root,i);
}

/*bool SumTree(node* root)
{
    int LeftSum;
    int RightSum;
    if(root == NULL || (root->left == NULL && root->right == NULL))return true;
    if(SumTree(root->left) && SumTree(root->right))
    {
        if(root->left == NULL)LeftSum = 0;
        else if(root->left->left == NULL && root->left->right == NULL)
        {
            LeftSum = root->left->data;
        }
        else
        {
            LeftSum = 2*(root->left->data);
        }
        if(root->right == NULL)RightSum = 0;
        else if(root->right->left == NULL && root->right->right == NULL)
        {
            RightSum = root->right->data;
        }
        else
        {
            RightSum = 2*(root->right->data);
        }
        if(root->data == (RightSum + LeftSum))return true;
        else return false;
    }
    return false;
}*/

void SumTree(node* root)
{
    if(root != NULL)
    {
        sum += root->data;
        SumTree(root->right);
        SumTree(root->left);
    }
}

int main()
{
    cout << "Enter Number of node : ";int n;cin >> n;
    node* root = NULL;
    for(int i=0;i<n;i++)
    {
        int x;cout << "Enter data : ";cin >> x;
        root = InsertNode(root,x);
    }
    cout << "\nLevel order of the given tree : ";LevelPrint(root);
    cout << "\n\n";
    SumTree(root);
    //if(SumTree(root))cout << "\nGiven Tree is a SumTree";
    if((sum-root->data) == root->data)cout << "\nGiven tree is a SumTree";
    else cout << "\nGiven tree is not a sumTree";
    return 0;
}
