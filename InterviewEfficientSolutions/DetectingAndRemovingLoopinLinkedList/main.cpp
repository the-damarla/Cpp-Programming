#include <bits/stdc++.h>

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

void insertNode(node** head, int data)
{
    if(*head == NULL)
    {
        node* newnode = getnode(data);
        *head = newnode;
        return;
    }
    node* temp = *head;
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

void DetectAndRemoveLoop(node** head)
{
    node* slow = *head,*fast = *head;
    if(fast == NULL || fast->next == NULL)
    {
        cout << "No Loop";
        return;
    }
    slow = slow->next;
    fast = fast->next->next;
    bool flag = false;
    while(fast != NULL && fast->next != NULL)
    {
        if(fast == slow)
        {
            flag = true;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(flag)
    {
        slow = *head;
        while(1)
        {
            if(slow->next == fast->next)
                break;
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
        cout << "\nLoop is detected at  : " << slow->data << "\n";
        cout << "The loop is removed & the list is : " ;PrintList(head);
    }
    else
    {
        cout << "\nNo Loop Detected\n";
        cout << "The list is : " ;PrintList(head);
    }
}

int main()
{
    cout << "Enter \'-1\' to stop giving input" << endl;
    node* head = NULL;
    while(1)
    {
        cout << "enter data : ";int x;cin >> x;
        if(x == -1)break;
        else insertNode(&head,x);
    }
    node* temp = head;
    while(temp->next != NULL)           /*keeping loop to 2nd node*/
        temp=temp->next;
    temp->next = head->next->next;
    //PrintList(&head);
    DetectAndRemoveLoop(&head);
    return 0;
}
