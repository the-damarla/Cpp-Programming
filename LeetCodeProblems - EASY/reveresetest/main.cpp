#include <iostream>
#include <cmath>

using namespace std;

int reverseint(int x) {
        int s = 0;
        int k = 0;
        cout << x << "\n";
        if(x < 0)
        {
            x = abs(x);
            k = 1;
        }
        cout << x << "\n";
        while(x != 0)
        {
            int temp = x % 10;
            s = s * 10 + temp;
            x = x / 10;
        }
        if(k == 1)
        {
            s = -s;
        }
        else if(s > pow(2,30)-1)
            return 0;
        else if(s < pow(-2,31))
            return 0;
        return s;
    }

int main()
{
    cout << "2147483648\n\n";
    int x = pow(2,30);
    cout << x << "\n";
    int k = reverseint(-2147483648);
    cout << k;
    return 0;
}
