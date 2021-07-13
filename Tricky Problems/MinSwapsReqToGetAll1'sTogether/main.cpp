#include <bits/stdc++.h>

using namespace std;

void MinSwaps(vector<int> v)
{
    int len = v.size();
    int WinLen = 0;
    for(int i=0;i<len;i++)
        if(v[i] == 1)WinLen++;                   //this is our Sliding Window length
    int MaxCount = 0;
    int CurCount = 0;
    int i=0,j=0;
    while(j < len)
    {
        CurCount += v[j];
        if((j-i+1) == WinLen)
        {
            MaxCount = max(MaxCount,CurCount);
            if(v[i] == 1)CurCount--;
            i++;                                //moving Start of our Window
        }
        j++;                                   //moving End of our Window
    }
    cout << "Minimum Swaps required to Make all 1's together is/are : " << (WinLen - MaxCount);
}

int main()
{
    cout << "Enter \'-1\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter data : ";int x;cin >> x;
        if(x == -1)break;
        else v.push_back(x);
    }
    MinSwaps(v);
    return 0;
}
