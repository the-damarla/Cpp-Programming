#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int x;
    int flag = 0;
    cout << "Enter a number : ";cin >> x;
    if(x <= 0)
        cout << "False";
    else if(x == 1)
    {
        cout << "True";
    }
    else
    {
        int temp = x;
        for(int i=0;i<=sqrt(x)+1;i++)
        {
            if(temp == pow(2,i))
            {
                cout << "True";
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0)
    {
        cout << "False";
    }
    else
        cout << "True";
    return 0;
}
