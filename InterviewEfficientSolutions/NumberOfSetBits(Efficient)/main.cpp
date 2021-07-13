#include <iostream>

using namespace std;

void better(int x)          //Time Complexity : O(log(n))
{
    if(x <= 0)
        return;
    int c = 0;
    while(x)
    {
        c += x % 2;
        x /= 2;
    }
    cout << "Better Solution gives : " << c;
}

void best(int x)            //Time Complexity : O(log(log(n)))
{
    int c = 0;
    if(x <= 0)
        return;
    while(x)
    {
        x = x & (x-1);
        c++;
    }
    cout << "Best Solution gives : " << c;
}

int main()
{
    cout << "Enter a number to find set bits : ";
    int x;cin >> x;
    best(x);
    cout << "\n";
    better(x);
    return 0;
}
