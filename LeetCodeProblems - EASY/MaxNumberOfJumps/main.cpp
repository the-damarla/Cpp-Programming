#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxjumps(vector<int> v)
{
    int len = v.size();
    int reach = 0;
    for(int i=0;i<len;i++)
    {
        if(reach < i)
            return reach;
        reach += max(reach,i+v[i]);
    }
    return reach;
}

int main()
{
    cout << "Hello world!" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter a Number : ";cin >> x;
        if(x < 10)
            v.push_back(x);
        else
            break;
    }
    int x = maxjumps(v);
    cout << "Output is : " << x;
    return 0;
}
