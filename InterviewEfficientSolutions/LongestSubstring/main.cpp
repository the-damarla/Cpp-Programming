#include <bits/stdc++.h>

using namespace std;

int LongestSubString(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> v(m+1,vector<int> (n+1));
    //set<string> k;
    int maxi = INT_MIN;
    //int row=0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i == 0 || j == 0)
                v[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
            {
                v[i][j] = 1 + v[i-1][j-1];
                maxi = max(maxi,v[i][j]);
            }
            else
                v[i][j] = 0;
        }
    }
    //string sub = s1.substr(row - maxi,maxi);
    //cout << sub << "\n";
    return maxi;
}

int main()
{
    cout << "Enter a string : ";string s1;cin >> s1;
    cout << "Enter an other string : ";string s2;cin >> s2;
    int k = LongestSubString(s1,s2);
    cout << "Longest Substring is of length : " << k;
    return 0;
}
