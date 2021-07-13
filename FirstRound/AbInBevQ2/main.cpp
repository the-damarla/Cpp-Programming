#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter a string : " ;
    char s[10000];cin >> s;
    set<string> k;
    for(int i=4;s[i] != '\0';i++)
    {
        bool flag = false;
        if(s[i-4] == '-')
        {
            for(int j=i-4;j<i;j++)
            {
                if(s[i] >= '0' && s[i] <= '9')
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        string v = "";
        if(flag)
        {
            for(int j=i-4;j<i;j++)
            {
                v += s[j];
            }
            k.insert(v);
        }
    }
    cout << "\n";
    for(auto x:k)
        cout << x << " ";
    cout << "\nNumber of distinct years are : " << k.size();
    return 0;
}
