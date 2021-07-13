#include <bits/stdc++.h>

using namespace std;

int CalMinJumps(vector<int> v,int n)
{
    if(n <= 1)return 0;
    if(v[0] == 0)return -1;
    int ladder = v[0];
    int stairs = v[0];
    int jump = 1;
    for(int level=1;level<n;level++)
    {
        if(level == n-1)
            return jump;
        if(level + v[level] > ladder)
            ladder = level + v[level];
        stairs--;
        if(stairs == 0)
        {
            jump++;
            stairs = ladder - level;
        }
    }
    return jump;
}

int main()
{
    cout << "Enter \'-1\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter an element : ";int x;cin >> x;
        if(x == -1)break;
        else v.push_back(x);
    }
    int jumps = CalMinJumps(v,v.size());
    cout << "Min jumps required to reach the end is/are : " << jumps;
    return 0;
}
