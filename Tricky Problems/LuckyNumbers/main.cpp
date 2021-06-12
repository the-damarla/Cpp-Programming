#include <bits/stdc++.h>

using namespace std;

bool check(long n)
{
    for(long i=2;i<sqrt(n)+1;i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool converter(long n)
{
    long sum1 = 0,sum2 = 0;
    while(n > 0)
    {
        long temp = n % 10;
        sum1 = sum1 + temp;
        sum2 = sum2 + temp * temp;
        n = n / 10;
    }
    bool flag1 = check(sum1);
    bool flag2 = check(sum2);
    return flag1 && flag2;
}

int main()
{
    cout << "Enter 1st boundary(inclusive) : ";
    long n1;cin >> n1;
    cout << "Enter 2nd Boundary(inclusive) : ";
    long n2;cin >> n2;
    if(n1 == 1)
    {
        n1 = 2;
    }
    vector<long> v;
    for(long i=n1;i<=n2;i++)
    {
        v.push_back(i);
    }
    vector<long> k;
    for(auto x:v)
    {
        bool y = converter(x);
        if(y)
        {
           k.push_back(x);
        }
    }
    cout << "Lucky number are : ";
    for(auto x:k)
        cout << x << " ";
    cout << "\n" << k.size();
    return 0;
}
