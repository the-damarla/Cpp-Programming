#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter \'-1\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter data : ";cin >> x;
        if(x == -1)break;
        v.push_back(x);
    }
    int n = v.size();
    int ind = 0;
    int mini = v[0];
    for(int i=1;i<n-1;i++)
    {
        if(v[i] < mini)
        {
            mini = v[i];
            ind = i;
        }
    }
    cout << "Index is " << ind << " value is " << v[ind] ;
    return 0;
}
