#include <bits/stdc++.h>

using namespace std;

/*Usually       a->1 b->2 c->3 d->4 ........... i->9 j->10# k->11# l->12#.........x->24# y->25# z->26#
    when letters are repeating they're denoted with (no.of repetitions) Ex : aaabccc ---> 1(3)23(3)
    So we have to return an array of size 26(1 based indexing,initialized with 0) which consists of frequency of every letter
Test Cases : i/p : 1226#24# ---> interpretation : abzx -----> o/p : 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1
             i/p : 1(2)23(3) --> interpretation : aabccc ----> o/p : 2 1 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
             i/p : 2110#(2) ---> interpretation : bajj ----> o/p : 1 1 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
             i/p : 23#(2)24#25#26#23#(3) ---> interpretation : wwxyzwww ----> o/p : 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 5 1 1 1*/

vector<int> Encoder(string s)
{
    int n = s.length();
    vector<int> ans(26,0);
    for(int i=n-1;i>=0;i--)
    {
        string freq ="";
        if(s[i] == ')')
        {
            i--;
            while(s[i] !='(')
            {
                freq+=s[i];
                i--;
            }
            i--;
        }
        reverse(freq.begin(),freq.end());
        string num = "";
        if(s[i] == '#')
        {
            num += s[i-2];
            num += s[i-1];
            i -= 2;
            cout << num << " ";
            int k = stoi(num);
            ans[k-1] += (freq == "")?1:stoi(freq);
            continue;
        }
        if(s[i] >= '1' && s[i] <= '9')
        {
            num += s[i];
            int k = stoi(num);
            ans[k-1] += (freq == "")?1:stoi(freq);
        }
    }
    return ans;
}

int main()
{
    cout << "Enter string : ";string s;cin >> s;
    vector<int> ans = Encoder(s);
    cout << "\n\n";
    for(auto x:ans)
        cout << x << " ";
    return 0;
}
