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

/*
node* reversenode(node* head,int n)
{
    node *cur,*prev = NULL,*next;
    cur = head;
    int c = 0;
    while(cur != NULL && c < n)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        c++;
    }
    return prev;
}
*/

void reversebetween(node* head, int start, int last)
{
    if(!head || start == last) return;
    node temp;
    temp.next = head;
    node* NodeBeforesublist = &temp;
    int pos = 1;
    while(pos < start)
    {
        NodeBeforesublist = NodeBeforesublist->next;
        pos++;
    }
    node* workingptr = NodeBeforesublist->next;
    while(start < last)
    {
        node* NodeToBeExtracted = workingptr->next;
        workingptr->next = NodeToBeExtracted->next;
        NodeToBeExtracted->next = NodeBeforesublist->next;
        NodeBeforesublist->next = NodeToBeExtracted;
        start++;
    }
}

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
        cout << "Enter input : ";int x;cin >> x;
        if(x == -1)
            break;
        else
            insertnode(&head,x);
    }
    cout << "Before reversing : ";
    printnode(head);
    cout << "\n";
    int start,last;
    cout << "Enter a position where you want to start reversing : ";cin >> start;
    cout << "Enter a position Till where you want to reverse : ";cin >> last;
    reversebetween(head,start,last);
    cout << "After reversing : ";printnode(head);
    return 0;
}
