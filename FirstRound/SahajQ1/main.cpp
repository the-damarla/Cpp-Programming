#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "You're expected to enter number of spells in the book : ";int n;cin >> n;
    vector<string> spells;
    for(int i=0;i<n;i++)
    {
        string spell;cout << "Enter Spell by spell : ";cin >> spell;
        spells.push_back(spell);
    }
    cout << "Enter Harry spelled spell : ";string HSpell;cin >> HSpell;
    int start = 0;
    bool flg = false;
    string k = "";
    int len = HSpell.size();
    for(int i=0;i<len;i++)
    {
        string spell = HSpell.substr(start,i+1);
        //cout << spell << "\n";
        if(find(spells.begin(),spells.end(),spell) != spells.end())
        {
            k += spell;
            start = i+1;
            flg = true;
            if(k == HSpell)break;
        }
        else
        {
            flg = false;
        }
    }
    if(flg)cout << "\n\nHarry";
    else cout << "\n\nValmorde";
    return 0;
}
