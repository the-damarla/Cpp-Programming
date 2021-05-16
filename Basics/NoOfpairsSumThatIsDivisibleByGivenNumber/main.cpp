#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the size of the array : ";
    int n; cin >> n;
    int *p = new int[n];
    cout << "enter the array elements : \n";
    for(int i=0;i<n;i++)
    {
        cin >> *(p+i);
    }
    cout << "Enter Element to check pair divisibility : ";
    int k,c = 0; cin >> k;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((*(p+i)+ *(p+j)) % k == 0)
               {
                   c++;
               }
        }
    }
    cout << "Number of pairs sum that is divisible by given number " << k << " is/are " << c;
    return 0;
}
