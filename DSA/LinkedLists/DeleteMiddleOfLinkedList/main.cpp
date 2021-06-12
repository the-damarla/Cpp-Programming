#include <iostream>

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

void insertnode(node** head, int data)
{
    node* temp = *head;
    if(temp == NULL)
    {
        node* newnode = getnode(data);
        *head = newnode;
        return;
    }
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
    cout << temp->data << " " ;
    printnode(&temp->next);
}

void deletemiddle(node** head)
{
    node* temp = *head;
    int c = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    if(c == 1)
    {
        return;
    }
    temp = *head;
    for(int i=1;i<c/2-1;i++)
        temp = temp->next;
    temp->next = temp->next->next;
}

int main()
{
    cout << "Enter \"-1\" to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == -1)
            break;
        else
            insertnode(&head,x);
    }
    cout << "Entered list is : ";printnode(&head);
    cout << "\nAfter deleting middle element : ";deletemiddle(&head);printnode(&head);
    return 0;
}
