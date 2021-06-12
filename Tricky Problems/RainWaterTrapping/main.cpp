#include <bits/stdc++.h>

using namespace std;

void RainTrap(vector<int> v, int n)      //here we are calculating left max and right max for every element in the list. So that subtraction of v[i] from
{                                       // min of that lmax & ramx gives that area trappind and addition of that whole trap gives the final result.
    vector<int> lmax(n,0),rmax(n,0);
    int res = 0;
    lmax[0] = v[0];
    for(int i=1;i<n;i++)
    {
        lmax[i] = max(v[i],lmax[i-1]);
    }
    rmax[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rmax[i] = max(v[i],rmax[i+1]);
    }
    for(int i=1;i<n-1;i++)
    {
        res += min(lmax[i],rmax[i]) - v[i];
    }
    cout << "Maximum water we can trap is : " << res;
}

int main()
{
    cout << "Enter \"-1\" TO stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == -1)
            break;
        else
            v.push_back(x);
    }
    RainTrap(v,v.size());
    return 0;
}
