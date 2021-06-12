#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a string : " ;
    string s;cin >> s;
    int len = s.size();
    char c = s[0];
    int coun = 0;
    for(int i=1;i<len;i++)
    {
        if(s[i] == c)
        {
            coun++;
        }
        else
            c = s[i];
    }
    cout << "\nOutput is : " << coun ;
    return 0;
}
