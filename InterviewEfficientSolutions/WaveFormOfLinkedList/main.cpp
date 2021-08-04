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
};

void InsertNode(node** head,int data)
{
    if(*head == NULL)
    {
        *head = getNode(data);
        return;
    }
    node* temp = *head;
    InsertNode(&temp->next,data);
}

void PrintList(node* head)
{
    if(head == NULL)return;
    cout << head->data << "->";
    PrintList(head->next);
}
/*
void WaveList(node** head)
{
    node* temp = *head;
    if(temp == NULL || temp->next == NULL)return;
    node* TempNext = temp->next;
    while(TempNext)
    {
        if(temp->data > TempNext->data)
        {
            swap(temp->data,TempNext->data);
        }
        if(TempNext->next && TempNext->next->data > TempNext->data)
        {
            swap(TempNext->data,TempNext->next->data);
        }
        temp =TempNext->next;
        TempNext = (temp) ? temp->next : NULL;
    }
}
*/

void WaveList(node** head)
{
    node*  temp = *head;
    if(temp==NULL || temp->next == NULL)return;
    bool flag = true;
    while(temp->next)
    {
        if(flag)
        {
            if(temp->data > temp->next->data)
            {
                swap(temp->data,temp->next->data);
            }
        }
        else
        {
            if(temp->data < temp->next->data)
            {
                swap(temp->data,temp->next->data);
            }
        }
        temp = temp->next;
        flag = !flag;
    }
}
int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    node* head= NULL;
    while(1)
    {
        int x;cout << "enter data : ";cin >> x;
        if(x ==0)break;
        InsertNode(&head,x);
    }
    PrintList(head);cout << "NULL\n";
    WaveList(&head);cout << "\n";
    PrintList(head);cout << "NULL\n";
    return 0;
}
