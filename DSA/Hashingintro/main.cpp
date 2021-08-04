#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter a string : " ;string s;cin >> s;
    unordered_map<int,int> mp;
    int len = s.size();
    for(int i=0;i<len;i++)
    {
        mp[s[i]]++;
    }
    for(auto x:mp)
        cout << (char)x.first << " -> " << x.second << "\n";
    return 0;
}
