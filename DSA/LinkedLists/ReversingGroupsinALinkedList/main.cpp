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

node* reverselist(node* head,int k)
{
    node *next,*prev,*cur = head;
    prev = NULL;
    /*int cnt = 0;
    while(cur)
    {
        cur = cur->next;
        cnt++;
    }
    if(cnt < k)
        return head;
    //cnt = 0;
    cur = head;*/
    int c = 0;
    while(cur != NULL && c < k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;c++;
    }
    if(next != NULL)
    {
        head->next = reverselist(next,k);
    }
    return prev;
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
    cout << "Enter \'-1\' to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == -1)
            break;
        else
            insertnode(&head,x);
    }
    cout << "Given list is : "; printnode(head);
    cout << "Enter size of Groups : "; int x;cin >> x;
    head = reverselist(head,x);
    cout << "After reversing groups : ";printnode(head);
    return 0;
}
