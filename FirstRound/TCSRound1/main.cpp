#include <iostream>

using namespace std;

bool NextPrime(int n)
{
    if(n <= 3)return true;
    if(n%2==0 || n%3 == 0)return false;
    for(int i=5;i*i <=n;i+=6)
    {
        if(n%i==0||(n%(i+2)==0))return false;
    }
    return true;
}

int GetPrime(int n)
{
    if(n==1)return 2;
    bool found = false;
    while(!found)
    {
        n++;
        if(NextPrime(n))
            return n;
    }
    return 0;
}

int GetFib(int n)
{
    //int f=0,s=1;
    int dp[n+1];
    dp[0] = 0;dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    cout << "Enter a digit : ";int n;cin >> n;
    bool flg = true;
    int itr1=1,itr2=1;
    cout << "\nThe number is : ";
    for(int i=0;i<n;i++)
    {
        if(flg)
        {
            itr1++;
            if(i == n-1)cout << GetFib(itr1);
        }
        else
        {
            itr2 = GetPrime(itr2);
            //cout << itr2 << " ";
            if(i == n-1)cout << itr2;
        }
        flg = !flg;
    }
    return 0;
}
