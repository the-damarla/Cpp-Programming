#include <iostream>
#include <math.h>

using namespace std;

void isprime(int x)
{
    int c = 0;
    if(x == 1 || x <= 0)
    {
        c = 1;
    }
    if(x == 2)
    {
        cout << x << " ";
    }
    for(int i=2;i<sqrt(x)+1;i++)
    {
        if(x % i == 0)
        {
            c++;
        }
    }
    if(c == 0)
    {
        cout << x << " ";
    }
}

int main()
{
    int x,y;
    cout << "enter intervals in which u want to find primes in between them : ";
    cin >> x >> y;
    cout << "Primes in the interval of " << x << " and " << y << " are : ";
    for(int i=x;i<y+1;i++)
    {
        isprime(i);
    }
    return 0;
}
