#include <iostream>
#include <vector>

using namespace std;

void evenodd(vector<int> v, int n)       //complexity of O(n), using "Kadanes" Algorithm
{
    int res = 1;
    int c = 1;
    for(int i=1;i<n;i++)
    {
        if((v[i] % 2 == 0 && v[i-1] % 2 != 0) || (v[i] % 2 != 0 && v[i-1] % 2 == 0))
        {
            c++;
            res = max(res,c);
        }
        else
            c = 1;
    }
    cout << "\nMax Even Odd Sub-array length is : " << res ;
}

void evenodd(vector<int> v)      //Naive Approach O(n^2)
{
    int len = v.size();
    int c;
    int res = 1;
    for(int i=0;i<len;i++)
    {
        c = 1;
        for(int j=i+1;j<len;j++)
        {
            if((v[j] % 2 == 0 &&v[j-1] % 2 != 0) || (v[j] % 2 != 0 && v[j-1] % 2 == 0))
                c++;
            else
                break;
        }
        res = max(res,c);
    }
    cout << "Max length is : " << res;
}

int main()
{
    cout << "Enter \"-1\" to stop giving inputs" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == -1)
            break;
        else
            v.push_back(x);
    }
    evenodd(v);
    evenodd(v,v.size());
    return 0;
}
