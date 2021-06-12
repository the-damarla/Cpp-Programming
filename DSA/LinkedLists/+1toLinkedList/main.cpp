#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

void printnode(node** head);

node* getnode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void reverselist(node** head)
{
    node *cur,*prev,*next;
    cur = *head;
    prev = NULL;
    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void plusone(node** head)
{
    reverselist(head);
    node* temp = *head;
    while(temp != NULL)
    {
        if(temp->data < 9)
        {
            temp->data++;
            reverselist(head);
            return;
        }
        else
        {
            temp->data = 0;
            if(temp->next == NULL)
            {
                temp->next = getnode(1);
                reverselist(head);
                return;
            }
        }
        temp = temp->next;
    }
}

void insertnode(node** head, int data)
{
    node* newnode = getnode(data);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    node* temp = *head;
    insertnode(&temp->next,data);
}

void printnode(node** head)
{
    node* temp = *head;
    if(temp->next == NULL)
    {
        cout << temp->data;
        return;
    }
    cout << temp->data << " ";
    printnode(&temp->next);
}

int main()
{
    cout << "Enter \'-1\' to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == -1)
            break;
        else
            insertnode(&head,x);
    }
    cout << "Number u entered : ";
    printnode(&head);
    plusone(&head);
    cout << "\nAfter adding 1 to it : ";
    printnode(&head);
    return 0;
}
