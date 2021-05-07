#include <iostream>

using namespace std;

int reverseof(int x)
{
    int num = 0;
    while(x > 0)
    {
        int rem = x % 10;
        num = num * 10 + rem;
        x = x / 10;
    }
    return num;
}

int main()
{
    int x;
    cout << "Enter a number to check whether it is a palindrome or not : ";
    cin >> x;
    int rev = reverseof(x);
    //cout << rev << endl;
    if(x == rev)
    {
        cout << "Given Number " << x << " is a Palindrome.";
        return 0;
    }
    cout << "Given number " << x << " is Not a Palindrome.";
    return 0;
}
