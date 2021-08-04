#include <bits/stdc++.h>

using namespace std;

void FindEquilibrium(vector<int> v,int n)
{
    int totsum = 0;
    for(auto x:v)
        totsum += x;
    int leftsum = 0;
    for(int i=0;i<n-1;i++)
    {
        totsum -= v[i];
        //cout << i << " -----> " << leftsum << "   " << totsum << "\n";
        if(leftsum == totsum)
        {
            cout << "At index -- > " << i << " ---> " << v[i] << "\n";
        }
        leftsum += v[i];
    }
    return;
}

int main()
{
    cout << "Enter \'-1\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == -1)break;
        v.push_back(x);
    }
    FindEquilibrium(v,v.size());
    return 0;
}
