#include <bits/stdc++.h>

using namespace std;

void permute(string s,int l,int r,vector<string> &ans)
{
    if(l==r)
        ans.push_back(s);
    for(int i=l;i<=r;i++)
    {
        swap(s[l],s[i]);
        permute(s,l+1,r,ans);
        swap(s[l],s[i]);
    }
}

vector<string> permutations(string s)
{
    vector<string> ans;
    permute(s,0,s.size()-1,ans);
    return ans;
}

int main()
{
    cout << "Enter a string : ";string s;cin >> s;
    vector<string> ans = permutations(s);
    for(auto x: ans)
        cout << x << "\n";
    return 0;
}
