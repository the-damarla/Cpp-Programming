#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    return (a.first < b.first);
}

int main()
{
    cout << "Enter number of Monsters : " ;int n;cin >> n;
    cout << "Enter initial experience : ";int exp;cin >> exp;
    vector<int> mons(n,0),power(n,0);
    for(int i=0;i<n;i++)
        cin >> mons[i];
    for(int i=0;i<n;i++)
        cin >> power[i];
    map<int,int> game;
    for(int i=0;i<n;i++)
    {
        game.insert({mons[i],power[i]});
    }
    vector<pair<int,int>> v;
    for(auto& x:game)
        v.push_back(x);
    sort(v.begin(),v.end(),cmp);
    int c = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i].first <= exp)
        {
            c++;
            exp += v[i].second;
        }
    }
    cout << c << " ";
    return 0;
}
