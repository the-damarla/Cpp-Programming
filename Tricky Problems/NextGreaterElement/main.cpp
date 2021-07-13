#include <bits/stdc++.h>

using namespace std;

void NextGreat(vector<int> v)
{
    int len = v.size();
    vector<int> rev;
    stack<int> stck;
    for(int i=len-1;i>=0;i--)
    {
        if(stck.empty())
        {
            rev.push_back(-1);
            stck.push(v[i]);
        }
        else
        {
            while(stck.empty() == false && stck.top() <= v[i])
            {
                stck.pop();
            }
            int k = stck.empty() ? -1 : stck.top();
            rev.push_back(k);
            stck.push(v[i]);
        }
    }
    cout << "Given Array : ";
    for(auto x:v)
        cout << x << " ";
    cout << "\nNext Greater elements : ";
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
    NextGreat(v);
    return 0;
}
