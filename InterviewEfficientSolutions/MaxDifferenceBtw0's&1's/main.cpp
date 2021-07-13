#include <bits/stdc++.h>

using namespace std;

void MaxDifference(vector<int> v,int n)
{
    int res = 0;
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        maxi += (v[i] == 0) ? 1:-1;
        /*v[i] = (v[i]==0)?1:-1;
        maxi = max(maxi,maxi+v[i]);*/
        if(maxi < 0)maxi = 0;
        res = max(res,maxi);
    }
    cout << "max Difference is : " << res;
}

int main()
{
    cout << "Enter \'-1\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == -1)break;
        else v.push_back(x);
    }
    MaxDifference(v,v.size());
    return 0;
}
