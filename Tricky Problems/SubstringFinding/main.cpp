#include <iostream>
#include <algorithm>

using namespace std;

/*Test Case :
    Enter main String : coronavirus
    Enter Number of Test Cases : 3
    Enter String to check : abcde
    Enter String to check : crnas
    Enter String to check : onarous

O/p : NEGATIVE
      POSITIVE
      NEGATIVE*/

int main()
{
    cout << "Enter Main String : " ;
    string s;cin >> s;
    cout << "Enter Number of test cases : ";int n;cin >> n;
    for(int i=0;i<n;i++)
    {
        string k;cout << "Enter string to check : ";cin >> k;
        int c = 0;
        int len = k.size();
        for(int j=0;j<len;j++)
        {
            if(find(s.begin()+j,s.end(),k[j]) != s.end())c++;
        }
        if(c == len)
            cout << "Positive\n";
        else
            cout << "Negative\n";
    }
    return 0;
}
