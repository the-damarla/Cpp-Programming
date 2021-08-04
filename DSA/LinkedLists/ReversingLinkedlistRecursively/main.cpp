#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* getNode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertnode(node** head,int data)
{
    node* temp = *head;
    if(temp == NULL)
    {
        *head = getNode(data);
        return;
    }
    insertnode(&temp->next,data);
}

void printlist(node* head)
{
    if(head == NULL)return;
    cout << head->data << " ";
    printlist(head->next);
}

node* ReverseCommonly(node* head)
{
    node* cur = head,*prev=NULL,*next;
    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

node* ReverseRecursive(node* head)
{
    if(head == NULL || head->next == NULL)return head;
    node* temp = ReverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        int x;cout << "Enter data : ";cin >> x;
        if(x == 0)break;
        insertnode(&head,x);
    }
    cout << "Given List -> ";printlist(head);
    head = ReverseCommonly(head);
    cout << "\nReverse of the list --> ";printlist(head);
    cout << "\nGiven list --> ";printlist(head);
    cout << "\nRecursively Reverse ---> ";printlist(ReverseRecursive(head));
    return 0;
}
