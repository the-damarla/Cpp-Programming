#include <bits/stdc++.h>

using namespace std;

void FibResolved(vector<int> &fib, int n)
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=n;i++)
    {
        fib[i] = (fib[i-1] + fib[i-2]) % 10;
    }
}

int fibanocci(long long int n)
{
    vector<int> fib(60,0);
    FibResolved(fib,60);
    for(auto x:fib)
        cout << x << " ";
    cout << "\n\n";
    return fib[n % 60];
}

int main()
{
    cout << "Enter Number to get its last digit in fib series : ";
    long long int n;cin >> n;
    cout << "The last digit is : " << fibanocci(n);
    return 0;
}
