#include <bits/stdc++.h>

using namespace std;

int LargestArea(vector<int> v, int n)
{
    stack<int> stck;
    int res = 0, tp;
    for(int i=0;i<n;i++)
    {
        while(!stck.empty() && v[stck.top()] >= v[i])
        {
            tp = stck.top();stck.pop();
            int cur = v[tp] * (stck.empty() ? i : (i-stck.top()-1));
            res = max(res,cur);
        }
        stck.push(i);
    }
    while(!stck.empty())
    {
        tp = stck.top();stck.pop();
        int cur = v[tp] * (stck.empty() ? n : (n-stck.top()-1));
        res = max(res,cur);
    }
    return res;
}

int LargestArea(vector<int> v)
{
    stack<int> stck;
    int len = v.size();
    vector<int> left(len,0),right(len,0);
    for(int i=0;i<len;i++)
    {
        while(!stck.empty() && v[stck.top()] >= v[i])
            stck.pop();
        left[i] = stck.empty() ? 0 : stck.top()+1;
        stck.push(i);
    }
    while(!stck.empty())
        stck.pop();
    for(int i=len-1;i>=0;i--)
    {
        while(!stck.empty() && v[stck.top()] >= v[i])
            stck.pop();
        right[i] = stck.empty() ? len-1 : stck.top()-1;
        stck.push(i);
    }
    int res = 0;
    for(int i=0;i<len;i++)
    {
        res = max(res,v[i] * (right[i] - left[i] +1));
    }
    return res;
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "enter an element : ";int x;cin >> x;
        if(x == 0)break;
        else v.push_back(x);
    }
    cout << "Largest Rectangle can be formed is : " << LargestArea(v);
    cout << "\n(Efficient)Largest Rectangle can be formed is : " << LargestArea(v,v.size());
    return 0;
}
