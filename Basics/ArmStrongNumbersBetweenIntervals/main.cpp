#include <iostream>

using namespace std;

void Armstrong(int x)
{
    int num,sum = 0;
    int temp = x;
    while(x > 0)
    {
        num = x % 10;
        sum = sum + (num * num * num);
        x = x / 10;
    }
    //cout << temp << " " << sum << "\n";
    if(temp == sum)
    {
        cout << sum << " ";
    }
}

int main()
{
    cout << "Enter intervals to find ARMSTRONG NUMBERS between them : ";
    int x,y;
    cin >> x >> y;
    cout << "Armstrong Numbers between " << x << " and " << y << " is/are : ";
    for(int i=x;i<y;i++)
    {
        Armstrong(i);
    }
    //Armstrong(371);
    return 0;
}
