#include <bits/stdc++.h>

using namespace std;

void Segregate(vector<int> v,int n)
{
    int c = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i] % 2 == 0)
        {
            swap(v[i],v[c]);
            c++;
        }
    }
    cout << "\nArray is : ";
    for(int i=0;i<n;i++)
        cout << v[i] << " ";
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == 0)break;
        else v.push_back(x);
    }
    Segregate(v,v.size());
    return 0;
}
