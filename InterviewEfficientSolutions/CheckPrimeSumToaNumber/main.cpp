#include <bits/stdc++.h>

using namespace std;

bool primeCheck(int n)
{
    if(n < 2)return false;
    if(n == 2)return true;
    for(int i=2;i*i<=n;i++)
    {
        if(n % i == 0)return false;
    }
    return true;
}

int main()
{
    cout << "Enter a number : " ;int n;cin >> n;
    vector<int> k;
    for(int i=2;i<=n;i++)
        if(primeCheck(i))
            k.push_back(i);
    int len = k.size();
    bool flag = true;
    for(int i=0;i<len;i++)
    {
        for(int j=len-1;j>=0;j--)
        {
            if(k[i] + k[j] == n)
            {
                cout << k[i] << " + " << k[j] << " = " << n;
                flag = false;
                break;
            }
        }
        if(!flag)break;
    }
    return 0;
}
