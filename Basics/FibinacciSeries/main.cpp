#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number which takes series up to : ";cin >> n;
    int first = 0;
    int second = 1;
    int temp;
    for(int i=0;i<n;i++)
    {
        cout << first << " ";
        temp = first + second;
        second = first;
        first = temp;
    }
    return 0;
}
