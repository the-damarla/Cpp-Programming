#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* getnode(int data)
{
    node* newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

void insertnode(node** head, int data)
{
    node* newnode = getnode(data);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    node* temp = *head;
    insertnode(&temp->next,data);
}

void uniquenodes(node** head)
{
    node* temp = *head;
    vector<int> v;
    int k = 0;
    while(temp != NULL)
    {
        k = 0;
        int y = temp->data;
        for(auto x:v)
            if(x == y)
            {
                k = 1;
                break;
            }

        if(k == 0)
            v.push_back(temp->data);
        temp = temp->next;
    }
    temp = *head;
    cout << "\nVector elements are : ";
    for(auto x :v)
        cout << x << " ";
    int len = v.size();
    for(int i=0;i<len-1;i++)
    {
        temp->data = v[i];
        temp = temp->next;
    }
    temp->data = v[len-1];
    temp->next = NULL;
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
    /*while(temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }*/
}

int main()
{
    cout << "Enter \"0\" to stop the input" << endl;
    node* head = NULL;
    while(1)
    {
        cout << "Enter input : ";int x;cin >> x;
        if(x == 0)
        {
            break;
        }
        else
        {
            insertnode(&head,x);
        }
    }
    printnode(&head);
    uniquenodes(&head);
    cout << "\nAfter eliminating Duplicate elements : ";
    printnode(&head);
    return 0;
}
