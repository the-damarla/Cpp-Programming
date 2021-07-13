#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* getnode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

void insertNode(node** head,int data)
{
    node* temp = *head;
    if(temp == NULL)
    {
        *head = getnode(data);
        return;
    }
    insertNode(&temp->next,data);
}

void PrintList(node* head)
{
    if(head == NULL)return;
    cout << head->data << " ";
    PrintList(head->next);
}

void ReversePrint(node* head)
{
    if(head == NULL)return;
    ReversePrint(head->next);
    cout << head->data << " ";
}

node* ReverseList(node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    node* temp = ReverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

node* Reverese(node* head)
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

int main()
{
    cout << "Enter \'-1\' to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == -1)break;
        else insertNode(&head,x);
    }
    cout << "\nGiven List : ";
    PrintList(head);
    cout << "\n\nReversePrint of the list : ";
    ReversePrint(head);
    cout << "\n\nAfter Reversing the list : ";
    head = ReverseList(head);
    PrintList(head);
    cout << "\n\nReverse print of the Reversed list : ";
    ReversePrint(head);
    cout << "\n\nReversing : ";
    head = Reverese(head);
    PrintList(head);
    return 0;
}
