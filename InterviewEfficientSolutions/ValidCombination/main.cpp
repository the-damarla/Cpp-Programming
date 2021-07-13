#include <bits/stdc++.h>

using namespace std;

/*Test Cases :     size    sum         possible Combinations
                size : 3  sum : 7 ----> 1 2 4
                size : 3  sum : 9 ----> 1 2 6 ;  1 3 5 ; 2 3 4
*/

void GetCombos(vector<int> v,int n,int r, int index,vector<int> k,int i,int sum)
{
    if(index == r)
    {
        int s = 0;
        for(auto x : k)
            s += x;
        if(s == sum)
        {
            for(auto x : k)
                cout << x << " ";
            cout << "\n";
        }
        return;
    }
    if(i >= n)return;
    k[index] = v[i];
    GetCombos(v,n,r,index+1,k,i+1,sum);
    GetCombos(v,n,r,index,k,i+1,sum);
}

int main()
{
    cout << "Enter size of the combination & sum of the combination" << endl;
    cout << "Enter the size of the combination : ";int r;cin >> r;
    cout << "Enter sum of the combination : ";int s;cin >> s;
    vector<int> v(9,0);
    for(int i=0;i<9;i++)
    {
        v[i] = i+1;
    }
    vector<int> k(r,0);
    GetCombos(v,v.size(),r,0,k,0,s);
    return 0;
}
