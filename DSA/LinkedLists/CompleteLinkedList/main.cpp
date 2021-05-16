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
    node* newnode = new node();
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
};

void insertnode(int data)
{
    node* newnode = getnode(data);
    newnode->next = head;
    head = newnode;
}

int length()
{
    node* temp = head;
    int c = 0;
    while(temp->next != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c+1;
}

void sortlist()
{
    int len = length();
    node* temp = head;
    for(int i=0;i<len;i++)
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
    cout << "After Sorting : ";
}

void insertlast(int data)
{
    node* newnode = getnode(data);
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

void insertat(int data, int pos)
{
    node* newnode = getnode(data);
    node* temp = head;
    if(pos == 0)
    {
        insertnode(data);
        return;
    }
    for(int i=1;i<pos-1;i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    int len = length();
    cout << "\ncurrent length of list is " << len << "\n\n";
}

void deleteat(int pos)
{
    node* temp = head;
    if(pos == 0)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        node* temp1 = temp->next;
        temp->next = temp1->next;
    }
    int len = length();
    cout << "\ncurrent length of list is " << len << "\n\n";
}

void reverselist()
{
    node* current,*next,*prev;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void print()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "  ->  ";
        temp = temp->next;
    }
    int len = length();
    cout << "\ncurrent length of list is " << len << "\n\n";
}

void leftrotate()
{
    node* temp = head;
    node* newnode = getnode(temp->data);
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    temp = head;
    head = temp->next;
    free(temp);
}

void rigthrotate()
{
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    node* newnode = getnode(temp->data);
    int len = length();
    temp = head;
    for(int i=1;i<len-1;i++)
    {
        temp = temp->next;
    }
    //free(temp->next);
    temp->next = NULL;
    newnode->next = head;
    head = newnode;
}

int searchelement(int s)
{
    node* temp = head;
    int c = 0,len = length();
    for(int i=1;i<len;i++)
    {
        if(temp->data == s)
        {
            break;
        }
        c++;
        temp = temp->next;
    }
    return c+1;
}

int main()
{
    while(1)
    {
        int x; cout << " \n\n enter 1 to insert\n 2 to insert at position\n 3 to delete at position\n 4 to print the list"
        << "\n 5 to reverse the list \n 6 to insert at ending\n 7 to sort the list\n"
        << " 8 to left rotate list by given times : \n 9 to right rotate list by given times :"
        << "\n 10 to search the element  \n 11 to delete by element\n 12 to exit\n    Enter ur Choice : ";  cin >> x;
        switch(x)
        {
            case 1:
                cout << "Insert data : ";
                int data;
                cin >> data;
                insertnode(data);
                break;
            case 2:
                cout << "1st enter the data : ";int data1;
                cin >> data1;
                cout << "Enter Position : ";int pos;
                cin >> pos;
                insertat(data1,pos);
                break;
            case 3:
                int pos1;
                cout << "Enter position : ";cin >> pos1;
                deleteat(pos1);
                break;
            case 4:
                print();
                break;
            case 5:
                cout << "Reversed List : ";
                reverselist();
                print();
                break;
            case 6:
                cout << "Enter element to insert at end : ";
                int x;cin >> x;
                insertlast(x);
                print();
                break;
            case 7:
                cout << "Sorted List would be : ";
                sortlist();
                print();
                break;
            case 8:
                cout << "Enter number of rotations : ";cin >> x;
                for(int i=0;i<x;i++)
                {
                    leftrotate();
                }
                print();
                break;
            case 9:
                cout << "Enter number of rotations to right rotate : "; cin >> x;
                for(int i=0;i<x;i++)
                {
                    rigthrotate();
                }
                print();
                break;
            case 10:
                cout << "enter element to search : "; cin >> x;
                data = searchelement(x);
                cout << "Element " << x << " is found at position : " << data;
                break;
            case 11:
                cout << "Enter element to delete : "; cin >> x;
                data = searchelement(x);
                deleteat(data);
                break;
            case 12:
                exit(0);
            default:
                cout << "\n Enter valid choice : ";
        }
    }
    return 0;
}
