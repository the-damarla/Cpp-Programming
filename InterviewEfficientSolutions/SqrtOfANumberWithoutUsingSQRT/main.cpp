#include <iostream>

using namespace std;

void Check(int x,int sum, int next_odd,int c)
{
    if(sum >= x)
    {
        c = (sum == x) ? c : c-1;
        cout << "\nThe sqrt of " << x << " is : " << c;
        return;
    }
    Check(x,sum+next_odd,next_odd+2,c+1);
}

void Check(int x)
{
    int sum = 0;
    int next_odd = 1;
    int c = 0;
    while(sum < x)
    {
        sum += next_odd;
        next_odd += 2;
        c++;
    }
    c = (sum == x) ? c : (c-1);
    cout << "\nThe square root of " << x << " is : " << c;
}

int main()
{
    cout << "you are expected to enter a number : " ;
    int x;cin >> x;
    Check(x);
    Check(x,0,1,0);
    return 0;
}
