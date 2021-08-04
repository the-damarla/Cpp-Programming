#include <bits/stdc++.h>

using namespace std;

void GetWaveForm(vector<int> v, int n)
{
    bool flag = true;
    for(int i=0;i<n-1;i++)
    {
        if(flag)
        {
            if(v[i] > v[i+1])
            {
                swap(v[i],v[i+1]);
            }
        }
        else
        {
            if(!flag)
            {
                if(v[i] < v[i+1])
                {
                    swap(v[i],v[i+1]);
                }
            }
        }
        flag = !flag;
    }
    for(auto x:v)
        cout << x << " ";
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter data : ";cin >> x;
        if(x == 0)break;
        v.push_back(x);
    }
    GetWaveForm(v,v.size());
    return 0;
}
