#include <iostream>
#include <vector>

using namespace std;

void consec(vector<int> v)
{
    int len = v.size();
    int maxi = 0,c = 0;
    for(int i=0;i<len;i++)
    {
        if(v[i] == 1)
            c++;
        else if(v[i] == 0)
            c = 0;
        if(c > maxi)
            maxi = c;
    }
    cout << "Max count of consecutive One's is : " << maxi;
}

int main()
{
    cout << "Enter \"-1\" to stop giving the input " << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter an element : ";int x; cin >> x;
        if(x == -1)
            break;
        else
            v.push_back(x);
    }
    consec(v);
    return 0;
}
