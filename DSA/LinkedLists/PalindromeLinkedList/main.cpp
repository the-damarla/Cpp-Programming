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

bool checkpalindrome(node* head)
{
    vector<int> v;
    node* temp = head;
    while(temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int i = v.size()-1;
    int j = 0;
    while(j<i)
    {
        if(v[i] != v[j])
            return false;
        i--;j++;
    }
    return true;
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
    if(checkpalindrome(head))
        cout << "\nGiven List is a palindromic list";
    else
        cout << "\nGiven List is not a Palindromic List";
    return 0;
}
