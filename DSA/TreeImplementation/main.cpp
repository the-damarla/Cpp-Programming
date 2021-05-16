#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

vector <int> v;

node* root = NULL;

node* getnode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
};

node* insertnode(node* root,int data)
{
    if(root == NULL)
    {
        root = getnode(data);
    }
    else
    {
        if(data < root->data)
        {
            root->left = insertnode(root->left,data);
        }
        if(data > root->data)
        {
            root->right = insertnode(root->right,data);
        }
    }
    return root;
}

void inorder(node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        v.push_back(root->data);
        inorder(root->right);
    }
}

int main()
{
    cout << "Enter \"0\" to stop giving inputs" << endl;

    while(1)
    {
        cout << "Enter value : ";int x;cin >> x;
        if(x == 0)
        {
            break;
        }
        else
        {
            root = insertnode(root,x);
        }
    }
    inorder(root);
    cout << "\nEnter Kth smallest element you want : ";int x;cin >> x;
    cout << " " << v[x-1];
    return 0;
}
