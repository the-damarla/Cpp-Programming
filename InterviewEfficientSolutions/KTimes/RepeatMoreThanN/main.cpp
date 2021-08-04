#include <bits/stdc++.h>

using namespace std;

void FindRepeat(vector<int> v,int n,int k)
{
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(v[i]) == mp.end())
        {
            mp.insert({v[i],1});
        }
        else
            mp[v[i]]++;
    }
    cout << "Elements repeated more than n/k are ----- > ";
    for(auto x:mp)
    {
        if(x.second > n/k)
            cout << x.first << " ";
    }
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "enter data : ";int x;cin >> x;
        if(x == 0)break;
        v.push_back(x);
    }
    cout << "Enter K : ";int k;cin >> k;
    FindRepeat(v,v.size(),k);
    return 0;
}
