#include <bits/stdc++.h>

using namespace std;

void RightRotate(vector<int> &v, int n)
{
    int temp = v[n-1];
    for(int i=n-1;i>0;i--)v[i] = v[i-1];
    v[0] = temp;
    return;
}

int Search(vector<int> second,int n,int ser)
{
    for(int i=0;i<n;i++)if(ser == second[i])return i;
    return 0;
}

bool comp(vector<int> first,vector<int> second,int n)
{
    if(first == second)return true;
    for(int i=0;i<n;i++)
    {
        RightRotate(second,n);
        if(first == second)return true;
    }
    return false;
}

int main()
{
    cout << "Enter something" << endl;
    int n;cin >> n;
    vector<int> first(n,0),second(n,0);
    for(int i=0;i<n;i++)cin >> first[i];
    for(int i=0;i<n;i++)cin >> second[i];
    if(comp(first,second,n))cout << "Minimum Happiness is : 0";
    else
    {
        int sum = 0;
        RightRotate(second,n);
        for(int i=0;i<n;i++)
        {
            sum += abs(i-Search(second,n,first[i]));
            cout << i << " " << abs(i-Search(second,n,first[i])) << "\n";
        }
        cout << "Min Happiness is : " << sum ;
    }
    return 0;
}
