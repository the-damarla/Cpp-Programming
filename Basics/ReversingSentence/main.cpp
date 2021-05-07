#include <iostream>

using namespace std;

void reversestr(string x,int len)
{
    if(len == 1)
        cout << x[len-1] <<endl;
    else
    {
        cout << x[len-1];
        reversestr(x,len-1);
    }
}

int main()
{
    string x;
    getline(cin,x);
    int len = x.size();
    /*for(int i=len-1;i>=0;i--)        //printing Reverse
    {
        cout << x[i];
    }*/
    reversestr(x,len);               //printing with recursion
    return 0;
}
