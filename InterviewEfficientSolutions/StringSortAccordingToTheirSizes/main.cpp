#include <bits/stdc++.h>

using namespace std;

bool cmp(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size();
    return n < m;
}

int main()
{
    cout << "Enter number of words u give : " ;
    int x;cin >> x;
    vector<string> v;
    for(int i=0;i<x;i++)
    {
        cout << "Enter String : ";string s;cin >> s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto x : v)
        cout << x << " ";
    return 0;
}
