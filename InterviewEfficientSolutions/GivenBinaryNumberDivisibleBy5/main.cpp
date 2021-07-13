#include <iostream>

using namespace std;

void CheckDivisibility(string s)
{
    int k=0;
    int i = 0,even=0,odd=0;
    while(s[k])
    {
        if(i % 2 == 0)
        {
            even += (s[k] == '0' && s[k+1] == '1') ? 1 : 0;
            even += (s[k] == '1' && s[k+1] == '0') ? 2 : 0;
            even += (s[k] == '1' && s[k+1] == '1') ? 3 : 0;
        }
        else
        {
            odd += (s[k] == '0' && s[k+1] == '1') ? 1 : 0;
            odd += (s[k] == '1' && s[k+1] == '0') ? 2 : 0;
            odd += (s[k] == '1' && s[k+1] == '1') ? 3 : 0;
        }
        i++;k+=2;
    }
    cout << "Odd count : " << odd;
    cout << "\nEven Count : " << even;
    (abs(odd - even) % 5 == 0)? (cout << "\n" << s << " Divisible by 5") : (cout << "\n" << s << " not Divisible by 5");
}

int main()
{
    cout << "Enter a binary string : " ;
    string s;cin >> s;
    int len = s.size();
    if(len % 2 == 0)
        s = s;
    else
        s = '0' + s;
    CheckDivisibility(s);
    return 0;
}
