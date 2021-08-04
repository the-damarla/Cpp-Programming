#include <bits/stdc++.h>

using namespace std;

void SlideWindow(vector<int> v,int n)
{
    //As we know number of duplicate elements are of size 2 we can slide a window of size 2
    sort(v.begin(),v.end());
    cout << "The Unique Element is : ";
    for(int i=0;i<n-2;i+=2)
    {
        if(v[i] != v[i+1])
        {
            cout << v[i] << endl;
            break;
        }
    }
    return;
}

void FindUnique(vector<int> v)
{
    int len = v.size();
    int x = v[0];
    for(int i=1;i<len;i++)
    {
        x ^= v[i];
    }
    cout << "The Unique Element using XOR : " << x << endl;
    return;
}

void FindUnique(vector<int> v,int n)
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
    cout << "The unique Element finding using hashing : ";
    for(auto &x:mp)
    {
        if(x.second == 0)
        {
            cout << x.first << endl;
        }
    }
    return;
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
    FindUnique(v,v.size());
    FindUnique(v);
    SlideWindow(v,v.size());
    return 0;
}
