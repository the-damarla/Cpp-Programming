#include <iostream>

using namespace std;

string uniquestr(string s)
{
    string uni = "";
    int len = s.size();
    for(int i=0;i<len;i++)
    {
        int c = 0;
        for(int j=i;j<len;j++)
        {
            if(s[i] == s[j])
            {
                c++;
            }
        }
        if(c == 1)
        {
            uni = uni + s[i];
        }
    }
    return uni;
}

int frequency(string s)
{
    int len = s.size();
    string uni = uniquestr(s);
    int k = uni.size();
    for(int i=0;i<k;i++)
    {
        int c = 0;
        for(int j=0;j<len;j++)
        {
            if(uni[i] == s[j])
            {
                c++;
            }
        }
        cout << "Frequency of " << uni[i] << " is " << c << "\n" ;
    }
    return 0;
}

int main()
{
    string s;
    cout << "Enter a String :"; getline(cin, s);
    frequency(s);
    return 0;
}
