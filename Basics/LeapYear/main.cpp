#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Enter a year : "; cin >> x;
    if(x % 4 == 0)
    {
        if(x % 400 == 0 && x % 100 == 0)
        {
            cout << "LEAP YEAR";
        }
        else{
            cout << "Not a Leap YEAR";
        }
    }
    else
    {
        cout << "NOT A LEAP YEAR";
    }
    return 0;
}
