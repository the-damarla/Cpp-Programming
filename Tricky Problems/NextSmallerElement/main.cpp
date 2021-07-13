#include <bits/stdc++.h>

using namespace std;

void NextSmaller(vector<int> v)
{
    int len = v.size();
    stack<int> stck;
    vector<int> rev;
    for(int i=len-1;i>=0;i--)
    {
        while(stck.empty() == false && stck.top() >= v[i])
            stck.pop();
        int k = stck.empty() ? -1 : stck.top();
        rev.push_back(k);
        stck.push(v[i]);
    }
    cout << "Given Array of Numbers : ";
    for(auto x:v)
        cout << x << " ";
    cout <<"\nTheir Next Smaller No.'s : ";
    reverse(rev.begin(),rev.end());
    for(auto x:rev)
        cout << x << " ";
}

int main()
{
    cout << "Enter \"0\" to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter an element : ";int x;cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    NextSmaller(v);
    return 0;
}
