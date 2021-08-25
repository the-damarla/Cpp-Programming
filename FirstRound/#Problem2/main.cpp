#include <bits/stdc++.h>

using namespace std;

string RemoveDups(string s,int n)
{
    vector<int> cnt(26,0),visited(26,0);
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    string res = "";
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']--;
        if (!visited[s[i] - 'a'])
        {
            while (res.size() > 0 && res.back() > s[i] && cnt[res.back() - 'a'] > 0)
            {
                visited[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res += s[i];
            visited[s[i] - 'a'] = 1;
        }
    }
    return res;
}

int main()
{
    cout << "Enter a string : " ;string s;cin >> s;
    int n  = s.size();
    string res = RemoveDups(s,n);
    /*map<char,int> mp;
    for(int i=0;i<n;i++)
        mp[s[i]]++;
    for(auto x:mp)
    {
        cout << x.first;
    }*/
    cout << res ;
    return 0;
}
