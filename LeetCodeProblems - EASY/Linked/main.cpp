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

/*void insertnode(node** head, int data)
{
    node* newnode = getnode(data);
    if(*head ==  NULL)
    {
        *head = newnode;
        return;
    }
    node* temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}*/

void insertnode(node** head, int data)
{
    node* newnode = getnode(data);
    if(*head ==  NULL)
    {
        *head = newnode;
        return;
    }
    node* temp = *head;
    insertnode(&temp->next,data);
}

void print(node** head)
{
    node* temp = *head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void printrec(node** head)
{
    node* temp = *head;
    if((temp->next) == NULL)
    {
        cout << (temp->data) << "\n";
        return;
    }
    cout << (temp->data) << " ";
    printrec(&temp->next);
}

void partitionlist(node** head, node** even, node** odd)
{
    node* temp = *head;
    while(temp != NULL)
    {
        if(temp->data % 2 == 0)
        {
            insertnode(even, temp->data);
        }
        else
        {
            insertnode(odd, temp->data);
        }
        temp = temp->next;
    }
}

void partitionbypos(node** head, node** evenpos, node** oddpos)
{
    node* temp = *head;
    int c = 0;
    while(temp != NULL)
    {
        if(c % 2 == 0)
        {
            insertnode(evenpos, temp->data);
            c++;
        }
        else
        {
            insertnode(oddpos, temp->data);
            c = 0;
        }
        temp = temp->next;
    }
}

int main()
{
    cout << "Enter number \"0\" to stop giving input\n" << endl;
    node* head =  NULL;
    node* even = NULL;
    node* odd =  NULL;
    node* evenpos = NULL;
    node* oddpos = NULL;
    while(1)
    {
        cout << "enter a number to insert : ";
        int y;cin >> y;
        if(y == 0)
        {
            break;
        }
        else
        {
            insertnode(&head,y);
        }
    }
    cout << "\n\n";
    partitionlist(&head,&even,&odd);
    cout << "Elements in the list are : ";print(&head);
    cout << "Even elements of the list : ";print(&even);
    cout << "Odd elements of the list : ";print(&odd);cout << "\n\n";
    partitionbypos(&head,&evenpos,&oddpos);
    cout << "Elements in the list : "; print(&head);
    cout << "Elements at Even position : ";print(&evenpos);
    cout << "Elements at Odd position : ";print(&oddpos);
    cout << "\n\n";
    cout << "Printing List Through Recursion : "; printrec(&head);
    cout << "Printing Even List Through Recursion : ";printrec(&even);
    cout << "Printing Odd List Through Recursion : ";printrec(&odd);
    return 0;
}
