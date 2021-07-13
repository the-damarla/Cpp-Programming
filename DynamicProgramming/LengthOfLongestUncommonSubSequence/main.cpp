#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

void LongestUncommon(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)dp[i][0] = 1;
    for(int i=0;i<=n;i++)dp[0][i] = MAX;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char ch = s1[i-1];
            int k;
            for(k=j-1;k>=0;k--)
            {
                if(s2[k] == ch)break;
            }
            if(k == -1)dp[i][j] = 1;
            else dp[i][j] = min(dp[i-1][j],dp[i-1][k]+1);
        }
    }
    int ans = (dp[m][n] >= MAX) ? -1 : dp[m][n];
    cout << "uncommon subsequence is of length : " << ans;
}

int main()
{
    cout << "you're expected to enter 2 strings" << endl;
    cout << "Enter string 1 : ";string s1;cin >> s1;
    cout << "Enter string 2 : ";string s2;cin >> s2;
    LongestUncommon(s1,s2);
    return 0;
}
