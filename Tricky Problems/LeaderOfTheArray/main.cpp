#include <bits/stdc++.h>

using namespace std;

void Leaders(vector<int> v, int n)      //Time Complexity of Theta(N) but Space Complexity is O(N)
{
    vector<int> k;
    k.push_back(v[n-1]);
    int cur = v[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(cur < v[i])
        {
            cur = v[i];
            k.push_back(cur);
        }
    }
    reverse(k.begin(),k.end());
    for(auto x : k)
        cout << x << " ";
}

void Leaders(vector<int> v)          //Naive Solution Time Complexity is O(n^2) Space Complexity is O(1)
{
    int len = v.size();
    int c = 0;
    for(int i=0;i<len;i++)
    {
        c = 0;
        for(int j=i+1;j<len;j++)
        {
            if(v[j] >= v[i])
            {
                c++;
            }
        }
        if(c == 0)
        {
            cout << v[i] << " ";
        }
    }
}

int main()
{
    cout << "Enter \"-1\" to stop the input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == -1)
            break;
        else
            v.push_back(x);
    }
    cout << "Leaders of given array are : ";
    Leaders(v);
    cout << "\nLeaders of given array are : ";
    Leaders(v,v.size());
    return 0;
}
