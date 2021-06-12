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

void insertelement(node** head, int data)
{
    node* temp = *head;
    if(temp == NULL)
    {
        node* newnode = getnode(data);
        *head = newnode;
        return;
    }
    if(temp->data > data)
    {
        node* newnode = getnode(data);
        newnode->next = *head;
        *head = newnode;
        return;
    }
    while(temp->next != NULL && temp->next->data < data)
        temp = temp->next;
    node* newnode = getnode(data);
    newnode->next = temp->next;
    temp->next = newnode;
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
    cout << "Given list is : ";printnode(head);
    int x;cout << "enter data to insert : ";cin >> x;
    insertelement(&head,x);
    cout << "After inserting the element : " ;printnode(head);
    return 0;
}
