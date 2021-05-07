#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cout<< "Enter two numbers to find their GCD : ";
    cin >> x >> y;
    int gcd = 1;
    int great = y;
    if(x > y)
    {
        great = x;
    }
    for(int i=1;i<great;i++)
    {
        if(x % i == 0 && y % i == 0)
        {
            gcd = i;
        }
    }
    cout << "the HCF of " << x << " and " << y << " is " << gcd;
    return 0;
}
