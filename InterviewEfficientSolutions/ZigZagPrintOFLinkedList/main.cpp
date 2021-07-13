#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* getnode(int data)
{
    struct node* newnode = new node();
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

void PrintList(node** head)
{
    node* temp = *head;
    if(temp->next == NULL)
    {
        cout << temp->data;
        return;
    }
    cout << temp->data << " ";
    PrintList(&temp->next);
}

void ZigZag(node** head)
{
    node* temp = *head;
    if(temp == NULL)
    {
        cout << "Nothing to print";
        return;
    }
    node* TempNext = temp->next;

    while(TempNext)
    {
        swap(temp->data,TempNext->data);       //swapping their values
        temp = TempNext->next;                //Changing headPointer(temp) to temp->next->next
        TempNext = temp ? temp->next : NULL;  //if there exists temp->next then TempNext = temp->next else NULL
    }
    PrintList(head);
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == 0)break;
        else insertNode(&head,x);
    }
    PrintList(&head);
    cout << "\n";
    ZigZag(&head);
    return 0;
}
