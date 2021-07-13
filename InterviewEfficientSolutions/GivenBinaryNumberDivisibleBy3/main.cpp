#include <iostream>

using namespace std;

void CheckDivisibility(string s)
{
    int even=0,odd=0;
    int i = 1;
    int k = 0;
    while(s[k])
    {
        if(i % 2 == 0)
        {
            even += (s[k] == '1'? 1 : 0);
        }
        else
            odd += (s[k] == '1'?1:0);
        k++;i++;
    }
    cout << "even : " << even;
    cout << "\nOdd : " << odd;
    int dis = even - odd;
    dis % 3 == 0? cout << "\nGiven Number divisible by 3" : cout << "\nnot divisible by 3";
}

int main()
{
    cout << "Enter a binary string" ;
    string s;cin >> s;
    CheckDivisibility(s);
    return 0;
}
