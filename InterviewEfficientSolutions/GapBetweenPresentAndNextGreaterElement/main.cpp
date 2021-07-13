#include <bits/stdc++.h>

using namespace std;

void CalculateGap(vector<int> v,int n)
{
    stack<int> stck;
    vector<int> k;
    for(int i=n-1;i>=0;i--)
    {
        while(stck.empty() == false && v[stck.top()] <= v[i])
            stck.pop();
        int cur = (stck.empty())? 0 : (stck.top()-i);
        k.push_back(cur);
        stck.push(i);
    }
    reverse(k.begin(),k.end());
    for(auto x:k)
        cout << x << " ";
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 0)break;
        else v.push_back(x);
    }
    CalculateGap(v,v.size());
    return 0;
}
