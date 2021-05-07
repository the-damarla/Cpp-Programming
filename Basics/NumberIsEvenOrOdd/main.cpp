#include <iostream>

using namespace std;

int evenorodd(int x)
{
    if( x % 2 == 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    cout << "Enter number to check Even Or Odd : ";
    int x; cin >> x;
    int y = evenorodd(x);
    if(y == 1)
    {
        cout << "The number " << x << " is Even."<< endl;
        return 0;
    }
    cout << "The Number " << x << " is Odd" << endl;
}
