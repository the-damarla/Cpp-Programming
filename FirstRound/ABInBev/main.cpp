#include <bits/stdc++.h>

using namespace std;

int number(int n)
{
    int c = 0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)c++;
    }
    return c;
}

bool check(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)return false;
    }
    return true;
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "enter an element : ";int x;cin >> x;
        if(x == 0)break;
        else v.push_back(x);
    }
    int len = v.size();
    for(int i=0;i<len-1;i++)
    {
        if(check(v[i] && v[i+1]))
        {
            if(v[i] > v[i+1])
            {
                cout << i;
                break;
            }
        }
    }
    return 0;
}
