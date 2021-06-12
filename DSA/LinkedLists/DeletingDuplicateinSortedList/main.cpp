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
    newnode->next = NULL;
    newnode->data = data;
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

void sortnode(node* head)
{
    int c = 0;
    node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    for(int i=0;i<c;i++)
    {
        temp = head;
        while(temp->next != NULL)
        {
            if(temp->data > temp->next->data)
            {
                int x = temp->data;
                temp->data = temp->next->data;
                temp->next->data = x;
            }
            temp = temp->next;
        }
    }
}

void deldup(node* head)
{
    node* temp = head;
    while(temp->next != NULL)
    {
        if(temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        else
            temp = temp->next;
    }
}

void printnode(node* head)
{
    node* temp = head;
    if(temp->next == NULL)
    {
        cout << temp->data;
        return;
    }
    cout << temp->data << " ";
    printnode(temp->next);
}

int main()
{
    cout << "enter \"-1\" to stop giving inputs" << endl;
    node* head = NULL;
    while(1)
    {
        int x;cout << "enter an element : ";cin >> x;
        if(x == -1)
            break;
        else
            insertnode(&head,x);
    }
    cout << "Given list before sorting : ";printnode(head);
    cout << "\nList after sorting : ";sortnode(head);printnode(head);
    cout << "\nAfter deleting duplicate elements : ";deldup(head);printnode(head);
    return 0;
}
