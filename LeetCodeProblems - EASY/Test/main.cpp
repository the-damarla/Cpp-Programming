#include <iostream>

using namespace std;

void check(int x)
{
    int temp,s=0;
    while(x > 0)
    {
        temp = x % 10;
        s = s * 10 + temp;
        x = x / 10;
    }
    cout << s << "\n";
}

void rec(int x)
{
    if(x > 1)
    {
        rec(x/2);
    }
    cout << x%2;
}

int main()
{
    cout << "Enter a number : " ;
    int x;cin >> x;
    check(x);
    int i = 1;
    long int bin = 0;
    int rem;
    rec(x);
    cout << "\n";
    while(x > 0)
    {
        rem = x % 2;
        //cout << rem << " ";
        bin = bin + rem * i;
        i = i * 10;
        x = x / 2;
    }
    cout << "  " << bin;
    return 0;
}
