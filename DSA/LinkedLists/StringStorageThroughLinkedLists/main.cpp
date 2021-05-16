#include <iostream>

using namespace std;

struct node
{
    string data;
    node* next;
};

node* head = NULL;

node* getnode(string data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertnode(string data)
{
    node* newnode = getnode(data);
    newnode->next = head;
    head = newnode;
}

int lenght()
{
    node* temp = head;
    int c = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

void sortlist()
{
    node* temp = head;
    int len = lenght();
    for(int i=0;i<len;i++)
    {
        temp = head;
        while(temp->next != NULL)
        {
            if(temp->data > temp->next->data)
            {
                string x = temp->data;
                temp->data = temp->next->data;
                temp->next->data = x;
            }
            temp = temp->next;
        }
    }
}

void print()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "  ->  ";
        temp = temp->next;
    }
}

int main()
{
    cout << "Enter the names : (Enter \"q or Q\" to stop giving input) :\n";
    while(1)
    {
        string data; cin >> data;
        if(data[0] == 'q' || data[0] == 'Q')
        {
            break;
        }
        insertnode(data);
    }
    print();
    sortlist();
    cout << "\nLexicographical Order of given list of names is : \n";
    print();
    return 0;
}
