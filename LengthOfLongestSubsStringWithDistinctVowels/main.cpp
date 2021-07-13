#include <bits/stdc++.h>

using namespace std;

void SubString(string s,int n)
{
    int len = s.size();
    int c = 0,maxi = 0;
    string subs;
    vector<string> w;
    for(int i=0;i<len+1;i++)
    {
        subs = "";
        c = 0;
        for(int j=i;j<len+1;j++)
        {
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')c++;
            if(c > n)
            {
                cout << (j-i)+1 << "      ";
                for(int k=i;k<j;k++)subs += s[k];
                w.push_back(subs);
                break;
            }
        }
        cout << "\n";
    }
    for(int i=0;i<w.size();i++)
    {
        int l=w[i].size();
        maxi = max(maxi,l);
    }
    if(maxi == 0)maxi = len;
    cout << "Length is : " << maxi;
}

int main()
{
    cout << "you are expected to enter a string and distinct number of vowels" << endl;
    string s;cout << "Enter string : ";cin >> s;
    cout << "number of vowels to be in that substring : ";int n;cin >> n;
    SubString(s,n);
    return 0;
}
