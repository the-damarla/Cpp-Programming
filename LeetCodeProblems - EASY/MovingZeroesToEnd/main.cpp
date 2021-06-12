#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Enter \"-1\" to stop giving input " << endl;
    vector <int> v;
    while(1)
    {
        int x;cout << "Enter input : ";cin >> x;
        if(x == -1)
            break;
        else
            v.push_back(x);
    }
    int coun = 0;
    int n = v.size();
    /*for(int i=0;i<n-1;i++)       //bruteForce
    {                             //Complexity of O(n^2)
        for(int j=0;j<n-1;j++)
        {
            if(v[j] == 0)
            {
                swap(v[j+1],v[j]);
            }
        }
    }*/
    for(int i=0;i<n;i++)
    {
        if(v[i] != 0)
        {
            swap(v[i],v[coun]);
            coun++;
        }
    }
    for(auto x: v)
        cout << x << " " ;
    return 0;
}
