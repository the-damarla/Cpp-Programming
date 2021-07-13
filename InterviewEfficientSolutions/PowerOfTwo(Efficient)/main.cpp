#include <iostream>

using namespace std;

bool check(int x)
{
    if(x <= 0)
        return false;
    return (x & (x-1)) == 0;
}

int main()
{
    cout << "Enter a number to know whether it is a power of \"2\" : ";
    int x;cin >> x;
    if(check(x))
        cout << "\nYES, Given number is power of \"2\"\n";
    else
        cout << "\nNO,Given number is not power of \"2\"\n";
    return 0;
}
