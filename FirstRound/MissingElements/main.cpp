#include <bits/stdc++.h>

using namespace std;

/*Test case :
    Input  : arr[] = {​​​12, 9, 10, 6, 18,14, 20}​​​
​    Output : Low = 6, High = 20
             Missing element = 7.8.11.13,15,16,17,19
*/

void Missing(vector<int> v,int n)
{
    int low = *min_element(v.begin(),v.end());
    int high = *max_element(v.begin(),v.end());
    cout << "low : " << low << "\n";
    cout << "high : " << high << "\n";
    map<int,int> mp;
    for(int i=low;i<=high;i++)
    {
        mp[i]++;
    }
    cout << "Missing elements are : ";
    for(auto x:mp)
    {
        if(find(v.begin(),v.end(),x.first) == v.end())cout << x.first << " ";
    }
}

int main()
{
    cout << "enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "enter element : ";cin >> x;
        if(x == 0)break;
        v.push_back(x);
    }
    Missing(v,v.size());
    return 0;
}
