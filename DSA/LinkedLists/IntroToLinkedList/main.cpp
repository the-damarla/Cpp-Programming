#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* head = NULL;

node* getnode(int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

void insertnode(int data)
{
    node* newnode = getnode(data);
    /*newnode->data = data;
    newnode->next = NULL;*/
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void print()
{
    node* temp = head;
    cout << "\n";
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int main()
{
    cout << "Start entering the elements of the linked list : \nGive 0 as input to stop giving input\n";
    while(1)
    {
        int x; cin >> x;
        if(x == 0)
        {
            break;
        }
        insertnode(x);
    }
    print();
    return 0;
}
