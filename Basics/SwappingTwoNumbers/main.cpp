#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "Enter Numbers to be swapped" ;
    cin >> x >> y;
    /*int temp;
    temp = x;
    x = y;
    y = temp;*/
    swap(x,y);
    cout << "Swapped numbers are " << x << " , " << y << endl;
    return 0;
}
