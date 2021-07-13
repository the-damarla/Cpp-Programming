#include <bits/stdc++.h>

using namespace std;

void GetCombos(vector<int> k,int n,int r,int index,vector<int> data,int i,vector<vector<int>> &v)
{
    if(index == r)
    {
        v.push_back(data);
        return;
    }
    if(i >= n)return;
    data[index] = k[i];
    GetCombos(k,n,r,index+1,data,i+1,v);
    GetCombos(k,n,r,index,data,i+1,v);
}

int main()
{
    cout << "Enter number of numbers : " ;int n;cin >> n;
    cout << "Enter size of the combos : ";int r;cin >> r;
    if(r==1)
    {
        cout << "\nPossible Pairs are : " << n;
        return 0;
    }
    if(r <=0)
    {
        n = 0;
        cout << "\nPossible Pairs are : " << n;
        return 0;
    }
    vector<int> k(n,0);
    for(int i=0;i<n;i++)
        k[i] = i+1;
    vector<int> data(r,0);
    vector<vector<int>> v;
    GetCombos(k,n,r,0,data,0,v);
    int c = 0;
    for(auto x:v)
    {
        vector<bool> flag(r-1,false);
        bool fl = true;
        for(int i=1;i<r;i++)
        {
            if(x[i] % x[i-1] == 0)
            {
                flag[i-1] = true;
            }
        }
        for(auto f:flag)
        {
            if(f == false)
            {
                fl = false;
                break;
            }
        }
        if(fl)
        {
            c++;
            for(auto y:x)
            {
                cout << y << " ";
            }
            cout << "\n";
        }
    }
    cout << "\nPossible pairs are : " << c+n;
    return 0;
}
