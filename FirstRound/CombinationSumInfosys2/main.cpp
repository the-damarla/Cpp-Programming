#include <bits/stdc++.h>

using namespace std;

set<vector<int>> ans;

void GetCombinations(vector<int> v,int n,int i,vector<int> data,int r)
{
    if(data.size() == r)
    {
        ans.insert(data);
        return;
    }
    if(i >= n || data.size() > r)return;
    if(data.size() == 0)
    {
        data.push_back(v[i]);
    }
    else
    {
        int k = data.size();
        if(v[i] % data[k-1] == 0)data.push_back(v[i]);
    }
    GetCombinations(v,n,i,data,r);
    cout << "--->" << i << "---> " << i << "\n";
    data.pop_back();
    GetCombinations(v,n,i+1,data,r);
    cout << "--->" << i << "---> " << i << "\n";
}

void GetCombos(vector<int> v,int n,int r)
{
    vector<int> data;
    GetCombinations(v,n,0,data,r);
    return;
}

int main()
{
    //cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    /*while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == 0)break;
        v.push_back(x);
    }*/
    int number;cout << "Enter number : ";cin >> number;
    for(int i=0;i<number;i++)v.push_back(i+1);
    //int n = v.size();
    cout << "Enter target sum : ";int r;cin >> r;
    GetCombos(v,number,r);
    /*for(int i=0;i<=n;i++)
    {
        GetCombos(v,n,i);
    }*/
    int c = 0;
    for(auto x:ans)
    {
        int z = x.size();
        if(z == r)
        {
            c++;
            for(auto y:x)
                cout << y << " ";
        }
        cout << "\n";
    }
    cout << "\nNumber of possible combinations are : " << c << endl;
    return 0;
}
