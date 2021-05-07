#include <iostream>

using namespace std;

int pow(int x)
{
    int mul = 1;
    if(x == 0)
        return 1;
    else
    {
        for(int i=0;i<x;i++)
        {
            mul = mul * 2;
        }
    }
    return mul;
}

void bintodec(int bin)
{
    int c = 0,sum = 0,temp = bin,rem;
    while(bin > 0)
    {
        rem = bin % 10;
        sum = sum + (rem * pow(c));
        bin = bin / 10;
        c++;
    }
    cout << "Decimal number of " << temp << " is " << sum;
}

int main()
{
    cout << "Enter a number to know its decimal value : ";
    int x;
    /*int a[100] = {0};     //This Method is Using Array
    int c = 0;
    cin >> x;
    while(x > 0)
    {
        a[c] = x % 2;
        x = x / 2;
        c++;
    }
    for(int i=c-1;i>=0;i--)
    {
        cout << a[i];
    }*/
    cin >> x;            //This method is without using Arrays
    int rem,i=1,bin = 0;
    while(x > 0)
    {
        rem = x % 2;
        bin = bin + rem * i;
        i = i * 10;
        x = x / 2;
    }
    cout << "The Decimal Number of " << x << " is " <<bin << "\n";
    bintodec(bin);
    return 0;
}
