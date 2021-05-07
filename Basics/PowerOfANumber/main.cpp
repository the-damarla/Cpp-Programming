#include <iostream>

using namespace std;

void power(int x, int y)
{
    int mul = 1;
    for(int i=1;i<y+1;i++)
    {
        mul = mul * x;
    }
    cout << x << " to the power of " << y << " is " << mul;
}

int main()
{
    int x,y;
    cout << "Enter Number to which we have to calculate Power : ";
    cin >> x;
    cout << "Enter power to which it has to be raise : ";
    cin >> y;
    power(x,y);
    return 0;
}
