#include <bits/stdc++.h>

using namespace std;

void FindNonRepeat(vector<int> v, int n)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(v[i]) == mp.end())
        {
            mp.insert({v[i],0});
        }
        else
        {
            mp[v[i]]++;
        }
    }
    cout << "The number doesn't occur is --- > ";
    for(auto x:mp)
    {
        if(x.second < 1)
        {
            cout << x.first << " , ";
        }
    }
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == 0)break;
        v.push_back(x);
    }
    FindNonRepeat(v,v.size());
    return 0;
}
