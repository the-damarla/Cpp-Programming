#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "Enter Two Numbers to find their LCM : ";
    cin >> x >> y;
    int great = x;
    if(y > x)
    {
        great = y;
    }
    int lcm = 1;
    while(1)
    {
        if(great % x == 0 && great % y == 0)
        {
            lcm = great;
            break;
        }
        great++;
    }
    cout << "LCM of " << x << " and " << y << " is :" << lcm;
    return 0;
}
