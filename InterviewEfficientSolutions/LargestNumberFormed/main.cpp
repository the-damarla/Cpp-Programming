#include <bits/stdc++.h>

using namespace std;

bool comparator(int a,int b)
{
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    return s1+s2 > s2+s1;
}

string LargestForm(vector<int> &v)
{
    string res = "";
    sort(v.begin(),v.end(),comparator);
    for(auto x:v)
        res += to_string(x);
    return res;
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    string s = LargestForm(v);
    cout << s ;
    return 0;
}
