#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Enter a number to get its multiplication table : "; cin >> x;
    for(int i=1;i<11;i++)
    {
        cout << x << " * " << i <<" = " << x*i << "\n";
    }
    return 0;
}
