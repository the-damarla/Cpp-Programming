#include <bits/stdc++.h>

using namespace std;

int GetMaxLengthBitonic(vector<int> v,int n)
{
    vector<int> increasing(n,1),decreasing(n,1),bitonic(n,0);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[j] < v[i])
            {
                increasing[i] = max(increasing[i],increasing[j]+1);
            }
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(v[j] < v[i])
            {
                decreasing[i] = max(decreasing[i],decreasing[j]+1);
            }
        }
    }
    cout << "increasing : " ;
    for(auto x:increasing)
        cout << x << " ";
    cout << "\ndecreasing : ";
    for(auto x:decreasing)
        cout << x << " ";
    for(int i=0;i<n;i++)
    {
        bitonic[i] = (increasing[i] + decreasing[i]) - 1;
    }
    cout << "\nBitonic : ";
    for(auto x: bitonic)
        cout << x << " ";
    return *max_element(bitonic.begin(),bitonic.end());
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
    int MaxLength = GetMaxLengthBitonic(v,v.size());
    cout << "\nThe max length of (increasing then decreasing) Bi-tonic Subsequence is : " << MaxLength;
    return 0;
}
