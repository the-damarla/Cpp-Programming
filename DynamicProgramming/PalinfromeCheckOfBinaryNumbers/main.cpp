#include <iostream>

using namespace std;

int pal = 0;
int c = 0;

void printbits(int n, int arr[])
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void SumFirstNbitsLastNbits(int n, int arr[])
{
    int sumf = 0,suml=0;
    for(int i=0;i<n/2;i++)
    {
        sumf += arr[i];
    }
    for(int i=n/2;i<n;i++)
    {
        suml += arr[i];
    }
    if(sumf == suml)
        c++;
}

void palindromeCheck(int n, int arr[])
{
    bool flag = true;
    int high = n-1,low = 0;
    while(low <= high)
    {
        if(arr[high] != arr[low])
        {
            flag = false;
            break;
        }
        low++;high--;
    }
    if(flag)
        pal++;
}

void generator(int n,int arr[],int i)
{
    if(i == n)
    {
        printbits(n,arr);
        palindromeCheck(n,arr);
        SumFirstNbitsLastNbits(n,arr);
        return;
    }
    arr[i] = 0;
    generator(n,arr,i+1);
    arr[i] = 1;
    generator(n,arr,i+1);
}

int main()
{
    cout << "Enter a number : " ;
    int x;cin >> x;
    int arr[2005];
    generator(x*2,arr,0);
    cout << "Number of palindromic strings : " << pal << "\n" ;
    cout << "Number of binary numbers of 1st n/2 bits sum == last n/2 bits sum are : " << c ;
    return 0;
}
