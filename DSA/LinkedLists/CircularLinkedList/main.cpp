#include <bits/stdc++.h>

using namespace std;

struct node
{
    node* next;
    int data;
};

node* GetNode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

node* insert(node *head,int data)
{
    node* temp = GetNode(data);
    if(head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        temp->next = head->next;
        swap(temp->data,head->data);
        head->next = temp;
    }
    return temp;
}

void PrintList(node* head)
{
    node* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
}

int main()
{
    cout << "Enter \'-1\' to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == -1)break;
        else{
            head = insert(head,x);
        }
    }
    PrintList(head);
    return 0;
}
