#include <bits/stdc++.h>

using namespace std;

int perfectcube(int x)
{
    return x*x*x;
}

int mincube(vector<int> v)
{
    int c=1,k;
    int len = v.size();
    while(1)
    {
        int cube = perfectcube(c);
        c++;
        k = 0;
        for(int i=0;i<len;i++)
        {
            if(cube % v[i] == 0)
            {
                k++;
            }
        }
        if(k == len)
        {
            return cube;
        }
    }
}

int main()
{
    cout << "Enter \"0\" to stop giving inputs\n";
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter input : ";cin >> x;
        if(x != 0)
            v.push_back(x);
        else
            break;
    }
    int x = mincube(v);
    cout << "Minimum cube for given array is : " << x ;
    return 0;
}
