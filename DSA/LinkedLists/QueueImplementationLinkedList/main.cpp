#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* front = NULL;
node* rear = NULL;

node* getnode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

void enqueue(int data)
{
    node* newnode = getnode(data);
    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if(front == NULL && rear == NULL)
    {
        cout << "Queue is empty";
    }
    else
    {
        if(front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
    }
}

void getfront()
{
    cout << "\nthe front is : " << front->data;
}

void getback()
{
    cout << "\nthe rear is : " << rear->data << "\n";
}

void printq()
{
    node* temp = front;
    while(temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(45);
    enqueue(100);
    enqueue(56);
    getfront();
    getback();
    enqueue(97);
    printq();
    cout << "\n\n";
    dequeue();
    dequeue();
    getfront();
    getback();
    cout << "\n";
    printq();
    return 0;
}
