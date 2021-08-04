#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter a string : " ;string s;cin >> s;
    int len = s.length();
    map<char,int> mp;
    for(int i=0;i<len;i++)
    {
        if(mp.find(s[i]) == mp.end())
        {
            mp.insert({s[i],0});
        }
        else
        {
            mp[s[i]]++;
        }
    }
    cout << "First occurring unique character is : ";
    for(int i=0;i<len;i++)
    {
        if(mp[s[i]]==0)
        {
            cout << s[i] << "\n";
            break;
        }
    }
    return 0;
}
