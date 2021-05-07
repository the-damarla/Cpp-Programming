#include <iostream>

using namespace std;

int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    (x >= y)?(x >= z)? cout << x << " is greatest" :(z >= x)? cout << z << " is greatest":cout << y << " is Greatest":(y >= z)?cout << y << " is greatest":cout << z << " is Greatest";
    return 0;
}
