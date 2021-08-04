#include <bits/stdc++.h>

using namespace std;

int FindLastStop(int n,vector<string> cmnds)
{
    vector<vector<int>> grid (n,vector<int>(n,0));
    int k = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            grid[i][j] = k;
            k++;
        }
    }
    cout << "\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    int len = cmnds.size();
    int r = 0,c=0;
    for(int i=0;i<len;i++)
    {
        if(cmnds[i] == "TOP" && (r > 0))r--;
        if(cmnds[i] == "DOWN" && (r < n-1))r++;
        if(cmnds[i] == "RIGHT" && (c < n-1))c++;
        if(cmnds[i] == "LEFT" && (c > 0))c--;
        else continue;
    }
    return grid[r][c];
}

int main()
{
    cout << "Enter square matrix size : ";int n;cin >> n;
    vector<string> cmnds;
    while(1)
    {
        string s;cout << "Enter a string : ";cin >> s;
        if(s == "0")break;
        cmnds.push_back(s);
    }
    cout << "The robot is at : " << FindLastStop(n,cmnds);
    return 0;
}
