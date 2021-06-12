#include <bits/stdc++.h>

using namespace std;

void MaxDiff(vector<int> v, int n)          //Time Complexity O(n)
{
    int maxi = v[1] - v[0];
    int mini = v[0];
    for(int i=1;i<n;i++)
    {
        maxi = max(maxi,v[i] - mini);
        mini = min(mini,v[i]);
    }
    cout << "\nMax Difference is : " << maxi;
}

void MaxDiff(vector<int> v)               //Naive Solution of Time Complexity O(n^2)
{
    int len = v.size();
    int diff = v[1] - v[0];
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(diff < (v[j]-v[i]))
            {
                diff = v[j] - v[i];
            }
        }
    }
    cout << diff;
}

int main()
{
    cout << "Enter \"-1\" To stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == -1)
            break;
        else
            v.push_back(x);
    }
    cout << "Max Difference is : ";
    MaxDiff(v);
    MaxDiff(v,v.size());
    return 0;
}
