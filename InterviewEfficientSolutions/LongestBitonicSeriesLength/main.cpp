#include <bits/stdc++.h>

using namespace std;

void Longest(vector<int> v,int n,vector<int> &k)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j] < v[i])
            {
                k[i] = max(k[i],k[j]+1);
            }
        }
    }
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter element : ";int x;cin >> x;
        if(x == 0)break;
        else v.push_back(x);
    }
    int n = v.size();
    vector<int> inc(n,1),dec(n,1);
    Longest(v,n,inc);
    reverse(v.begin(),v.end());
    Longest(v,n,dec);
    cout << "inc -- > ";
    for(auto x:inc)
        cout << x << " ";
    cout << "\n dec---> ";
    for(auto x:dec)
        cout << x << " ";
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi,(inc[i]+dec[i])-1);
    }
    cout << "\n\nLongest Bitonic is : " << maxi << "\n\n";
    return 0;
}
