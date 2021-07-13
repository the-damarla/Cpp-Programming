#include <iostream>

using namespace std;

/*Test case : a ---> 3   - 011
              b ---> 5   - 101
No. of bits to change are : 2
*/

int main()
{
    cout << "You will be asked to enter 2 two numbers" << endl;
    int a;cout << "enter a number : ";cin >> a;
    int b;cout << "Enter a number : ";cin >> b;
    int x = (a ^ b);
    int c = 0;
    while(x)
    {
        c++;
        x = x & (x-1);
    }
    cout << "number of bits to change are : " << c;
    return 0;
}
