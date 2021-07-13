#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* GetNode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

void InsertNode(node** head,int data)
{
    if(*head == NULL)
    {
        *head = GetNode(data);
        return;
    }
    node* temp = *head;
    InsertNode(&temp->next,data);
}

void PrintList(node* head)
{
    if(head == NULL)return;
    cout << head->data << " ";
    PrintList(head->next);
}

void RotateList(node** head,int k)
{
    node* temp = *head;
    int c = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        c++;
    }
    if(k > c)k %= c;
    temp->next = *head;
    temp = *head;
    for(int i=1;i<k;i++)
        temp = temp->next;
    *head = temp->next;
    temp->next = NULL;
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == 0)break;
        else InsertNode(&head,x);
    }
    cout << "Given List : ";
    PrintList(head);
    cout << "\nEnter Number of rotations : ";int k;cin >> k;
    RotateList(&head,k);
    cout << "\nAfter rotating : ";PrintList(head);
    return 0;
}
