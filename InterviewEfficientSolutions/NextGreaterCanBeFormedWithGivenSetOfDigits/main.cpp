#include <bits/stdc++.h>

using namespace std;

vector<int> FormVector(int n)
{
    vector<int> v;
    while(n)
    {
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(),v.end());
    return v;
}

bool GetGreater(vector<int> &v, int n)
{
    if(n == 1)return true;
    int i = 0;
    for(i=n-1;i>0;i--)
    {
        if(v[i] > v[i-1])break;
    }
    if(i != 0)
    {
        for(int j=n-1;j>=i;j--)
        {
            if(v[i-1] < v[j])
            {
                swap(v[i-1],v[j]);
                break;
            }
        }
        reverse(v.begin()+i,v.end());
        return true;
    }
    return false;
}

int main()
{
    cout << "Enter a number : ";int x;cin >> x;
    vector<int> vec = FormVector(x);
    if(GetGreater(vec,vec.size()))
    {
        GetGreater(vec,vec.size());
        cout << "Next greater number formed is --- > ";
        for(auto x: vec)
            cout << x ;
    }
    else
    {
        cout << "No Greater element is found greater";
    }
    return 0;
}
