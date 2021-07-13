#include <bits/stdc++.h>

using namespace std;

void Combinations(vector<int> arr, int n, int r, int index, vector<int> data,int i)
{
    if(index == r)
    {
        for(int j=0;j<r;j++)
        {
            cout << data[j] << " ";
        }
        cout << "\n";
        return;
    }
    if(i >= n)
        return;
    data[index] = arr[i];
    Combinations(arr,n,r,index+1,data,i+1);
    Combinations(arr,n,r,index,data,i+1);
}

void GetCombos(vector<int> k,int n,int r)
{
    vector<int> data(r,0);
    Combinations(k,n,r,0,data,0);
}

int main()
{
    cout << "Enter \"0\" to stop giving input" << endl;
    vector<int> k;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 0)break;
        else k.push_back(x);
    }
    int len = k.size();
    for(int i=1;i<=len;i++)
        GetCombos(k,len,i);
    return 0;
}
