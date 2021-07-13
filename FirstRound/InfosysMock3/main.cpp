#include <bits/stdc++.h>

using namespace std;

int Longest(vector<int> v,int n)
{
    vector<int> k(n,1);
    /*for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((v[j] & v[i]) * 2 < (v[j] | v[i]))
            {
                k[i] = max(k[i],k[j]+1);
            }
        }
    }*/
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j] * 2 < v[i])
            {
                k[i] = max(k[i],k[j]+1);
            }
        }
    }
    cout << "Given vector --> ";
    for(auto x:v)
        cout << x << " ";
    cout << "\nInc vector --> ";
    for(auto x:k)
        cout << x << " ";

    return *max_element(k.begin(),k.end());
}

int main()
{
    cout << "Enter size of the array : " ;int n;cin >> n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    {
        cout << "Enter " << i << "th element : ";cin >> v[i];
    }
    //cout << "\nAnswer : " << ;
    Longest(v,n);
    return 0;
}
