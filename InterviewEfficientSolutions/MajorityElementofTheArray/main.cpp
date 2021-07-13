#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> v, int k)
{
    int c,n;
    c = count(v.begin(),v.end(),k);
    n = v.size();
    if(c > n/2)
        return true;
    return false;
}

void majority(vector<int> v)
{
    int major=v[0];
    int c = 1;
    int n = v.size();
    for(int i=1;i<n;i++)
    {
        if(v[i] == v[i-1])
            c++;
        else
        {
            c--;
            if(c == 0)
            {
                major = v[i];
                c = 1;
            }
        }
    }
    //cout << "Check : " << major << "\n";
    if(check(v,major))
        cout << "Majority element is : " << major;
    else
        cout << "No Majority element found";
}

int main()
{
    cout << "Enter \"0\" to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    majority(v);
    return 0;
}
