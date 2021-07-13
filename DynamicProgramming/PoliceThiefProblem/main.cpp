#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void MaxCatch(vector<char> v, int n)
{
    stack<char> stck;
    //int sum = 0;
    int len = v.size();
    int c = 0;
    for(int i=0;i<len;i++)
    {
        while(v[i] != 'P')
        {
            stck.push(v[i]);
            i++;
        }
        if(v[i] == 'P' && !stck.empty())
        {
            for(int j=0;i<n;j++)
            {
                if(!stck.empty())
                {
                    stck.pop();c++;
                }
            }
            int k = n;
            while(!stck.empty() && k >= 0)
            {
                stck.pop();k--;
            }
        }
        if(v[i] == 'P' && stck.empty() && i+n < len && v[i+n] == 'T')
            c++;
    }
    cout << "\nThe sum is : " << c << "\n";
}

int main()
{
    cout << "Enter only \'P\' & \'T\' in the array and enter any other alphabet to stop giving input" << endl;
    vector<char> v;
    while(1)
    {
        char k;cout << "Enter char : ";cin >> k;
        if(k != 'P' && k!= 'T')
            break;
        else
            v.push_back(k);
    }
    cout << "Enter a value of each cop can catch : ";int n;cin >> n;
    MaxCatch(v,n);
    for(auto x:v)
        cout << x << " ";
    return 0;
}
