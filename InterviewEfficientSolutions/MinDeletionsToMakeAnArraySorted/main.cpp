#include <bits/stdc++.h>

using namespace std;

int MinDel(vector<int> v,int n)
{
    vector<int> k(n,1);
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
    int maxi = *max_element(k.begin(),k.end());
    return n-maxi;
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter an element : ";int x;cin >> x;
        if(x == 0)break;
        else v.push_back(x);
    }
    int del = MinDel(v,v.size());
    cout << "Number of min Deletions required are/is : " << del;
    return 0;
}
