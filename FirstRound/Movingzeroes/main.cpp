#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* getNode(int data)
{
    node* newnode = new node();
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
};

void InsertNode(node** head,int data)
{
    node* temp = *head;
    if(temp == NULL)
    {
        *head = getNode(data);
        return;
    }
    InsertNode(&temp->next,data);
};

void RemoveLoop(node** head)
{
    node* temp = *head;
    bool flag = false;
    node *slow = head,*fast = head;
    if(head == NULL || head->next == NULL)return;
    while(fast != NULL || fast->next!= NULL)
    {
        if(slow == fast)
        {
            flag = true;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(flag)
    {
        slow *head;
        while(1)
        {
            if(slow->next == fast->next)
            {
                fast->next = NULL;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
    }
    else{
        cout << "NO LOOP detected";
    }
}

int Fibanocci(int n,)
{
    if(n == 0)return 0;
}

int fibanocci(int n)
{
    vector<int> dp(1000000,0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n-1];
}



void printNode(node* head)
{
    if(head == NULL)return;
    printNode(head->next);
    cout << head->data << " ";
}

int main()
{
    node* head = NULL;
    while(1)
    {
        int x;cout << "enter data : ";cin >> x;
        if(x == 0)break;
        InsertNode(&head,x);
    }
    printNode(head);
}
