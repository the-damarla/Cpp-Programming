#include <iostream>

using namespace std;

int main()
{
    cout << "Enter levels : ";
    int x;cin >> x;
    for(int i=x;i>0;i--)
    {
        for(int j=1;j<=x;j++)
        {
            if(i <= j)
                cout << "#";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
