#include <iostream>

using namespace std;

int keepalpha(string s)
{
    int len = s.size();
    string s1 = "";
    for(int i=0;i<len;i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            s1 = s1 + s[i];
        }
    }
    cout << s1;
    return 0;
}

int main()
{
    string s;
    cout << "Enter the string : ";
    getline(cin,s);
    keepalpha(s);
    return 0;
}
