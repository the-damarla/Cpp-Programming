#include <iostream>
#include <vector>

using namespace std;

void maxsubarray(vector<int> v)
{
    int res = v[0];
    int maxi = v[0];
    int len = v.size();
    for(int i=1;i<len;i++)
    {
        maxi = max(v[i] + maxi,v[i]);
        res = max(res,maxi);
    }
    cout << "Max Sub-array sum is : " << res;
}

int main()
{
    cout << "Enter \"20\" To stop giving inputs" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 20)
            break;
        else
            v.push_back(x);
    }
    maxsubarray(v);
    return 0;
}
