#include <iostream>
#include <vector>

using namespace std;

void Twosum(vector <int> v, int sum)
{
    int n = v.size();
    cout << "[";
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(v[i] + v[j] == sum)
        {
            cout << i << "," << j;
            break;
        }
    }
    cout << "]";
}

int main()
{
    cout << "Enter \"0\" To stop giving Input" << endl;
    vector <int> v;
    while(1)
    {
        int x;cout << "Enter input : ";cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    cout << "Enter Target Sum : ";int x;cin >> x;
    Twosum(v,x);
    return 0;
}
