#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter a string : ";
    string s;cin >> s;
    char dt = s[3];
    char st = s[0];
    if(st == 'M')
    {
        cout << "State : Mizoram\n";
        if(dt == '0')
            cout << "Dist : Aizawal\n";
        if(dt == '1')
            cout << "Dist : Vijay\n";
    }
    else
    {
        cout << "State : Tripura\n";
        if(dt == '0')
            cout << "Dist : Agartala\n";
        if(dt == '1')
            cout << "Dist : Sai Nag\n";
    }
    string num = "";
    for(int i=6;i<10;i++)
        num += s[i];
    int sumnum = stoi(num);
    cout << sumnum;
    return 0;
}
