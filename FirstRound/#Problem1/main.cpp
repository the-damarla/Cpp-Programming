#include <bits/stdc++.h>

using namespace std;

void GetBinomialFactor(vector<vector<int>> &Secondpascal,int n)
{
    vector<int> store;
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
        store.push_back(res);
    }
    Secondpascal.push_back(store);
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
    //cout << "you're expected to enter total number of lines" << endl;
    cout << "Enter a number : ";int n;cin >> n;
    vector<vector<int>> pascal(n+1,vector<int> (n+1));
    GetPascal(pascal,n+1);
    cout << "[";
    for(int i=1;i<=n;i++)
    {
        cout << "[";
        for(int j=0;j<i-1;j++)
        {
            cout << pascal[i][j] << ",";
        }
        cout << pascal[i][i-1] << "]";
    }
    cout << "]";

    cout << "\n\n    **Second Method**  \n\n";

    vector<vector<int>> SecondPascal;
    for(int i=0;i<n;i++)
    {
        GetBinomialFactor(SecondPascal,i);
    }
    cout << "[";
    for(auto x:SecondPascal)
    {
        cout << "[";
        for(auto y:x)
        {
            cout << y << ",";
        }
        cout << "]";
    }
    cout << "]";
    return 0;
}
