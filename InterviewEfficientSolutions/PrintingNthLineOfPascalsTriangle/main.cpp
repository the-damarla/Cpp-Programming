#include <bits/stdc++.h>

using namespace std;

void GetBinomialFactor(int n) //Nth line of pascal triangle is ---> (Nc0,Nc1,......,NcN-1,NcN).
{
    for(int i=0;i<=n;i++)
    {
        int res = 1;
        int k = i;
        if(k > n-k)k=n-k;
        for(int j=0;j<k;++j)
        {
            res *= (n-j);
            res /= (j+1);
        }
        cout << res << " ";
    }
}

void GetPascal(vector<vector<int>> &v, int n)
{
    for(int level=0;level<n;level++)
    {
        for(int i=0;i<level;i++)
        {
            if(level == i || i == 0)
            {
                v[level][i] = 1;
            }
            else
            {
                v[level][i] =  v[level-1][i] + v[level-1][i-1];
            }
        }
    }
}

int main()
{
    cout << "you're expected to enter total number of lines" << endl;
    cout << "total lines : ";int n;cin >> n;
    vector<vector<int>> pascal(n,vector<int> (n));
    GetPascal(pascal,n);
    cout << "Enter the line u want : ";int level;cin >> level;
    if(level < n)
    {
        cout << "\n the " << level << "th line is ------> ";
        for(int i=0;i<level;i++)
        {
            cout << pascal[level][i] << " ";
        }
    }
    else
    {
        cout << "Not Possible to print";
    }
    cout << "\n\nActual Pascal Triangle is ---> \n";
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout << pascal[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nWithout Calculating whole Pascal Triangle " << level << "th level ----> ";GetBinomialFactor(level-1);
    cout << "\n";
    return 0;
}
