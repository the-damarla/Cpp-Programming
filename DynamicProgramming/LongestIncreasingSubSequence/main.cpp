#include <bits/stdc++.h>

using namespace std;

void getsequence(vector<int> v, vector<int> k, int ind)
{
    int temp = k[ind];
    cout << "\n\nThe Sequence is(reverse order) : " ;
    for(int i=ind;i>=0;i--)
    {
        if(k[i] == temp)
        {
            cout << v[i] << " ";
            temp--;
        }
    }
}

int maxel(vector<int> v,vector<int> k)
{
    int maxi = k[0];
    int ind = 0;
    int len = k.size();
    for(int i=1;i<len;i++)
    {
        if(maxi < k[i])
        {
            ind = i;
            maxi = k[i];
        }
    }
    getsequence(v,k,ind);
    return maxi;
}

void LongestSubSequence(vector<int> v, int n)
{
    vector<int> k(n,1);
    //k[0] = 1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(v[j] < v[i])
                k[i] = max(k[i],k[j]+1);

    cout << "\nArray of increasing notations : ";
    for(auto x:k)
        cout << x << " ";
    int el = maxel(v,k);
    cout << "\n\nLongest Increasing SubSequence is of length : " << el << "\n" ;
}

int main()
{
    cout << "Enter \"0\" to stop giving input " << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    LongestSubSequence(v,v.size());
    return 0;
}
