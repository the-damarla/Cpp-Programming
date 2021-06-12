#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << "Enter string : ";string s;cin >> s;
    int len = s.size();
    int flag = 0;
    stack <char> stck;
    for(int i=0;i<len;i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(' )
            stck.push(s[i]);
        else
        {
            if(stck.empty())
            {
                flag = 1;
                break;
            }
            else if(s[i] == '}')
            {
                if(stck.top() == '{')
                    stck.pop();
                else
                {
                    flag = 1;
                    break;
                }
            }
            else if(s[i] == ']')
            {
                if(stck.top() == '[')
                    stck.pop();
                else
                {
                    flag = 1;
                    break;
                }
            }
            else if(s[i] == ')')
            {
                if(stck.top() == '(')
                    stck.pop();
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    if(flag == 0 && stck.empty())
        cout << "OKAY";
    else
        cout << "Wrong";
    return 0;
}
