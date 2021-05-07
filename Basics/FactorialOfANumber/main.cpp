#include <iostream>

using namespace std;

void fact(int x)
{
    int mul = 1;
    for(int i=1;i<x+1;i++)
    {
        mul = mul * i;
    }
    cout << "The factorial of " << x << " is " << mul;
}

int main()
{
    int x;
    cout << "Enter a number : "; cin >> x;
    cout << "Factors are : ";
    for(int i=1;i<x+1;i++)
    {
        if(x % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    fact(x);
    return 0;
}
