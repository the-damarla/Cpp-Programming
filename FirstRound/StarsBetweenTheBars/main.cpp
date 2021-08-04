#include <bits/stdc++.h>

using namespace std;

vector<int> CountStarsBtwBars(string s,vector<int> start,vector<int> last)
{
    int len = start.size();
    vector<int> ans;
    for(int i=0;i<len;i++)
    {
        int bars = 0,stars = 0,countStars=0;
        for(int j=start[i]-1;j<last[i];j++)
        {
            if(s[j] == '|')
            {
                bars++;
                if(bars == 2)
                {
                    bars = 0;
                    stars+=countStars;
                    countStars = 0;
                }
            }
            else if(s[j] == '*' && bars == 1)
            {
                countStars++;
                //cout << countStars << " ";
            }
        }
        ans.push_back(stars);
    }
    return ans;
}

int main()
{
    cout << "Enter the string consisting of \'*\' & \'|\' : " ;
    string s;cin >> s;
    vector<int> start,last;
    cout << "Enter \'0\' in both start and last to stop giving input\n ";
    while(1)
    {
        cout << "Enter data of start :" ;int x;cin >> x;
        if(x == 0)break;
        start.push_back(x);
        cout << "Enter data of last : ";cin >> x;
        last.push_back(x);
    }
    vector<int> ans = CountStarsBtwBars(s,start,last);
    cout << "\n\n Answers \n\n";
    for(auto x:ans)
        cout << x << " ";
    return 0;
}
