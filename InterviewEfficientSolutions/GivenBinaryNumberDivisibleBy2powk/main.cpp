#include <iostream>
#include <math.h>

using namespace std;

void CheckDivisibleOf2k(string s, int n,int k)
{
    int c;
    for(int i=0;i<k;i++)
    {
        if(s[n-i-1] == '0')
            c++;
    }
    (c==k)?(cout << "Given " << s << " is divisible by " << pow(2,k)) : (cout << "Given " << s << " is not divisible by " << pow(2,k));
}

int main()
{
    cout << "Enter a binary string : " ;
    string s;cin >> s;
    cout << "Enter power of two(2) to check : ";int k;cin >> k;
    CheckDivisibleOf2k(s,s.size(),k);
    return 0;
}
