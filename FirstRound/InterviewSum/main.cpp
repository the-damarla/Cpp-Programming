#include <bits/stdc++.h>

using namespace std;

/*we have to find the element in the array to which it has all smaller elements to
its right left side and all larger elements to the right side
    Test Case :
                i/p : 1 2 3 4 5 6
                o/p : 2 3 4 5*/

vector<bool> LeadArray2(vector<int> v,int n)
{
    vector<bool> ans(n,false);
    int comp = v[n-1];
    for(int i=n-2;i>0;i--)
    {
        if(v[i] > comp)
        {
            //cout << "From lead2 " << v[i] << " " ;
            comp = v[i];
            ans[i] = true;
        }
    }
    return ans;
}


vector<bool> LeadArray(vector<int> v,int n)
{
    vector<bool> ans(n,false);
    int comp = v[n-1];
    for(int i=n-2;i>0;i--)
    {
        if(v[i] < comp)
        {
            //cout << "From Lead1 " << v[i] << " " ;
            comp = v[i];
            ans[i] = true;
        }
    }
    return ans;
}

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
    vector<bool> ans1,ans2;
    ans1 = LeadArray(v,v.size());
    cout << "\n";
    reverse(v.begin(),v.end());
    ans2 = LeadArray2(v,v.size());
    reverse(v.begin(),v.end());
    int n = v.size();
    for(int i=1;i<n-1;i++)
    {
        if(ans1[i] == ans2[i])
        {
            cout << "\nThe index is " << i  << " The Number is " << v[i] ;
        }
    }
    cout << "\nThis element has smaller elements to the left of it and larger elements to the right of it";
    return 0;
}
