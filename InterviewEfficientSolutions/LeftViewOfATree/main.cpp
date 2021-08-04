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
        root= getNode(data);
        return root;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp->left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = getNode(data);
            return root;
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = getNode(data);
            return root;
        }
    }
    return root;
}

void preOrder(node* root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


void inOrder(node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(node* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}


int maxHeight(node* root)
{
    if(root == NULL)return 0;
    return 1+max(maxHeight(root->left),maxHeight(root->right));
}

void PrintGivenLevel(node* root,int level,bool ltr)
{
    if(root == NULL)return;
    if(level==1)cout << root->data << " ";
    else if(level > 1)
    {
        if(ltr)
        {
            PrintGivenLevel(root->left,level-1,ltr);
            PrintGivenLevel(root->right,level-1,ltr);
        }
        else{
            PrintGivenLevel(root->right,level-1,ltr);
            PrintGivenLevel(root->left,level-1,ltr);
        }
    }
}

void PrintGivenLevel(node* root,int level)
{
    if(root == NULL)return;
    if(level == 1)cout << root->data << " ";
    else if(level > 1)
    {
        PrintGivenLevel(root->left,level-1);
        PrintGivenLevel(root->right,level-1);
    }
}

void PrintLevel(node* root)
{
    int h = maxHeight(root);
    bool ltr = true;
    for(int i=1;i<=h;i++)
    {
        PrintGivenLevel(root,i);
    }
    cout << "\nZigZag Traversal of the given tree : ";
    for(int i=1;i<=h;i++)
    {
        PrintGivenLevel(root,i,ltr);
        ltr = !ltr;
    }
}

void RightViewWithQueue(node* root)
{
    if(root == NULL)return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=1;i<=n;i++)
        {
            node* temp = q.front();
            q.pop();
            if(i==n)cout << temp->data << " ";
            if(temp->left!= NULL)q.push(temp->left);
            if(temp->right != NULL)q.push(temp->right);
        }
    }
}

void PrintRightView(node* root,int level,int *maxLevel)
{
    if(root == NULL)return;
    if(*maxLevel < level)
    {
        cout << root->data << " ";
        *maxLevel = level;
    }
    PrintRightView(root->right,level+1,maxLevel);
    PrintRightView(root->left,level+1,maxLevel);
}

void RightView(node* root)
{
    int maxLevel = 0;
    PrintRightView(root,1,&maxLevel);
}

void PrintLeftView(node* root,int level,int *maxLevel)
{
    if(root == NULL)return;
    if(*maxLevel < level)
    {
        cout << root->data << " ";
        *maxLevel = level;
    }
    PrintLeftView(root->left,level+1,maxLevel);
    PrintLeftView(root->right,level+1,maxLevel);
}

void LeftView(node* root)
{
    int maxLevel = 0;
    PrintLeftView(root,1,&maxLevel);
}

void LeftViewWithQueue(node* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=1;i<=n;i++)
        {
            node* temp = q.front();
            q.pop();
            if(i==1)cout << temp->data << " ";
            if(temp->left != NULL)q.push(temp->left);
            if(temp->right != NULL)q.push(temp->right);
        }
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
    cout << "\nHeight of the given tree is : " << maxHeight(root);
    cout << "\nPre-order of the tree : ";preOrder(root);
    cout << "\nIn-order of the tree : ";inOrder(root);
    cout << "\nPost-order of the tree : ";postOrder(root);
    cout << "\nLevelOrder Traversal of Given Tree : ";PrintLevel(root);
    cout << "\nLeft-view of the Given tree : ";LeftView(root);
    cout << "\nLeft-View of the given tree with Queue : ";LeftViewWithQueue(root);
    cout << "\nRight-view of the Given tree : ";RightView(root);
    cout << "\nRight-View of the given tree with Queue : ";RightViewWithQueue(root);
    cout << "\n";
    return 0;
}
