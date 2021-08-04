#include <bits/stdc++.h>

using namespace std;

void Segregate(vector<int> v)
{
    cout << "given array --- > ";
    for(auto x:v)
        cout << x << " ";
    cout << "\n";
    int c = 0;
    bool ltr = true;
    for(int i=0;i<v.size();i++)
    {
        if(ltr)
        {
            if(v[i] < 0)
            {
                swap(v[i],v[c]);
                c++;
            }
        }
        else
        {
            if(v[i] > 0)
            {
                swap(v[i],v[c]);
                c++;
            }
        }
        ltr = !ltr;
    }
    cout << "Segregated array ----- > ";
    for(auto x:v)
        cout << x << " ";
}


void Segregate(vector<int> v,int n)
{
    cout << "given array --- > ";
    for(auto x:v)
        cout << x << " ";
    cout << "\n";
    int c = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i] < 0)
        {
            swap(v[i],v[c]);
            c++;
        }
    }
    cout << "Segregated array ----- > ";
    for(auto x:v)
        cout << x << " ";
}

int main()
{
    cout << "Enter \'0\' to stop" << endl;
    vector<int> v;
    while(1)
    {
        cout << "enter data : ";int x;cin >> x;
        if(x == 0)break;
        v.push_back(x);
    }
    Segregate(v,v.size());
    cout << "\n\nALRENATE SEGREGATION \n\n";
    Segregate(v);
    return 0;
}
