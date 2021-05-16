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
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

void push(int data)
{
    node* newnode = getnode(data);
    newnode->next = head;
    head = newnode;
}

void pop()
{
    node* temp = head;
    head = temp->next;
    free(temp);
}

char top()
{
    return head->data;
}

void traverse()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool isempty()
{
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string s;
    cout << "Enter parenthesis order : ";cin >> s;
    int len = s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            push(s[i]);
        }
        else
        {
            if(isempty())
            {
                push('1');
                break;
            }
            if(s[i] == '}')
            {
                if(top() == '{')
                    pop();
                else
                    break;
            }
            if(s[i] == ']')
            {
                if(top() == '[')
                    pop();
                else
                    break;
            }
            if(s[i] == ')')
            {
                if(top() == '(')
                    pop();
                else
                    break;
            }
        }
    }
    if(isempty())
        cout << "Balanced ";
    else
        cout << "Unbalanced ";
    return 0;
}
