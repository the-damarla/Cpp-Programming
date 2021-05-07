#include <iostream>

using namespace std;

int main()
{
    int x,num = 0;
    cout << "enter number to reverse : "; cin >> x;
    while(x > 0)
    {
        int rem = x % 10;
        num = num * 10 + rem;
        x = x / 10;
    }
    cout << num;
    return 0;
}
