#include <bits/stdc++.h>

using namespace std;

void MinSwaps(vector<int> v,int n,int k)
{
    int TotCount = 0;
    for(int i=0;i<n;i++)(v[i] <= k)?TotCount++:TotCount+=0;
    int CurCount = 0,i=0,j=0,maxCount = 0;
    while(j < n)
    {
        (v[j] <= k)?CurCount++:CurCount+=0;
        if(j-i+1 == TotCount)
        {
            maxCount = max(maxCount,CurCount);
            if(v[i] <= k)CurCount--;
            i++;
        }
        j++;
    }
    cout << "MinSwaps Required are : " << TotCount - maxCount;
    return;
}

int main()
{
    cout << "Enter \'0\' to stop giving input " << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == 0)break;
        v.push_back(x);
    }
    cout << "Enter K : ";int k;cin >> k;
    MinSwaps(v,v.size(),k);
    return 0;
}
