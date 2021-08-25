#include<bits/stdc++.h>
using namespace std;

void getOut()
{
    string s;
    getline(cin,s);
    vector<int> v(26,0);
    int n = s.size();
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(int i=0;i<n;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            v[(int)(s[i]-'a')] = 1;
        }
    }
    bool flg = false;
    for(int i=0;i<26;i++)
    {
        if(v[i] == 0)
        {
            cout << (char)(i+'a');
            flg = true;
        }
    }
    if(!flg)cout << "0";
    return;
}

int main()
{
    int n;cin >> n;
    while(n)
    {
        getOut();
        cout << "\n";
        n--;
    }
    return 0;
}
