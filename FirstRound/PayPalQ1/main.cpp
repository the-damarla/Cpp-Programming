#include <bits/stdc++.h>

using namespace std;

long long int Num_of_ones(long long int N)
{
    long long int zp[100000],op[100000];
    zp[0] = 2;op[0] = 3;
    zp[1] = 3;op[1] = 4;
    for(long long int i=2;i<N;i++)
    {
        zp[i] = (2*zp[i-1] + 2*op[i-2])%1000000009;
        op[i] = (op[i-1] + 3 * zp[i-2])%1000000009;
    }
    return op[N-1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << "Enter a number : " ;long long int N;cin >> N;
    cout << Num_of_ones(N);
    return 0;
}
