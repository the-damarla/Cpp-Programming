#include <bits/stdc++.h>

using namespace std;

int SumOfArray(vector<int> v,int n,int i,int sum)
{
    if(i == n)
        return sum;
    return sum + v[i] + SumOfArray(v,n,i+1,sum);
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    int sum = 0;
    sum = SumOfArray(v,v.size(),0,sum);
    cout << "Sum is : " << sum;
    return 0;
}
