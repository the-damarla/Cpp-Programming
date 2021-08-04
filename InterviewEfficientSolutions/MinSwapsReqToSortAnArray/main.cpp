#include <bits/stdc++.h>

using namespace std;

void swap(vector<int> &arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void MinSwapsReq(vector<int> arr,int n)
{
    vector<int> temp = arr;
    sort(arr.begin(),arr.end());
    int ans = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[temp[i]] = i;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i] != temp[i])
        {
            ans++;
            int init = temp[i];
            swap(temp,i,mp[arr[i]]);

            mp[init] = mp[arr[i]];
            mp[arr[i]] = i;
        }
    }
    cout << "Min Swaps required are : " << ans ;
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == 0)break;
        v.push_back(x);
    }
    MinSwapsReq(v,v.size());
    return 0;
}
