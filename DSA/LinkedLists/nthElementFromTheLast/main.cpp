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

int printlastefficient(node** head, int n)
{
    node *first,*second;
    if(*head == NULL)
        return 0;
    first = second = *head;
    for(int i=0;i<n;i++)
    {
        if(first == NULL)
            return 0;
        first = first->next;
    }
    while(first != NULL)
    {
        first = first->next;
        second = second->next;
    }
    return second->data;
}

int lastnth(node** head, int n)          //naive Solution
{
    node* temp = *head;
    int c = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    if(n > c)
        return 0;
    temp = *head;
    /*for(int i=1;i<(c-n)+1;i++)
    {
        temp = temp->next;
    }
    return temp->data;*/
    while(temp != NULL)
    {
        if(c == n)
        {
            return temp->data;
        }
        c--;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    cout << "Enter \"-1\" to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        cout << "Enter an element : ";int x;cin >> x;
        if(x == -1)
            break;
        else
            insertnode(&head,x);
    }
    cout << "The list is : ";printnode(&head);
    cout << "\nNow enter a position that u want from the end : ";int x;cin >> x;
    cout << "The number you want is : " << lastnth(&head,x);
    cout << "\nThe number you wanted is :(efficient way) :  " << printlastefficient(&head,x);
    return 0;
}
