#include <bits/stdc++.h>

using namespace std;

int searchEl(vector<int> v,int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(v[i] == x)
            return i;
    }
    return -1;
}

void PrintPostOrder(vector<int> in,vector<int> pre,int len)
{
    int root = searchEl(in,pre[0],len);
    if(root != NULL)
    {
        PrintPostOrder(in,pre[]++,root);
    }
    if(root != n-1)
    {
        PrintPostOrder(in+root+1,pre+root+1,n-root-1);
    }
    cout << pre[0];
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    cout << "Enter data for in-order Traversal--> " << endl;
    vector<int> in;
    while(1)
    {
        cout << "enter data : ";int x;cin >> x;
        if(x == 0)break;
        in.push_back(x);
    }
    cout << "now enter PreOrder Traversal-->" << endl;
    int len = in.size();
    vector<int> pre(n,0);
    for(int i=0;i<len;i++)
    {
        cout << "Enter data : ";cin >> pre[i];
    }
    PrintPostOrder(in,pre,len);
    return 0;
}
