#include <iostream>

using namespace std;

int main()
{
    cout << "Enter Number of stairs u want : ";
    int x;cin >> x;
    x = x * 2;
    int mid1,mid2;
    mid1 = mid2 = x/2;
    for(int i=0;i<x/2;i++)
    {
        for(int j=0;j<x;j++)
        {
            if(j >= mid1 && j <= mid2)
        {
            cout << "#";
        }
        else
            cout << " ";
        }
        cout << "\n";
        mid1--;mid2++;
    }
    return 0;
}
