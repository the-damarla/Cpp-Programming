#include <bits/stdc++.h>

using namespace std;

int GetMaxSum(vector<int> v,int n)
{
    vector<int> maxi(n,0);
    for(int i=0;i<n;i++)
    {
        maxi[i] = v[i];
        for(int j=0;j<i;j++)
        {
            if(v[j] < v[i])
                maxi[i] = max(maxi[i],maxi[j]+v[i]);
        }
    }
    return *max_element(maxi.begin(),maxi.end());
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
    int sum = GetMaxSum(v,v.size());
    cout << "max Possible sum is : " << sum;
    return 0;
}
