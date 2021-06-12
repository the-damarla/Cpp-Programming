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
    cout << temp->data << " ";
    printnode(&temp->next);
}

void printmidefficint(node** head)    //Efficient way
{
    node* fast,*slow;
    fast = slow = *head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}

void printmiddle(node** head)      //Naive Solution
{
    node *temp = *head;
    int c = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    temp = *head;
    int store = c/2;
    c = 0;
    while(temp != NULL)
    {
        if(c == store)
        {
            cout << temp->data;
            return;
        }
        c++;
        temp = temp->next;
    }
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
    cout << "The given list is : ";printnode(&head);
    cout << "\nThe middle element is : ";printmiddle(&head);
    cout << "\nMiddle node in efficient way : ";printmidefficint(&head);
    return 0;
}
