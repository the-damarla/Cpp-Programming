#include <bits/stdc++.h>

using namespace std;

/*test case : 4 2 5 7
  o/p : 2 4 5 7
  Explanation : 2 ---> 10
                4 ---> 100
                5 ---> 101
                7 ---> 111*/

bool cmp(int one,int second)
{
    int sum1=0,sum2=0;
    while(one || second)
    {
        if(one)
        {
            one = one & (one-1);
            sum1++;
        }
        if(second)
        {
            second = second & (second-1);
            sum2++;
        }
    }
    return !(sum1>sum2);
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element :";cin >> x;
        if(x == 0)break;
        else v.push_back(x);
    }
    sort(v.begin(),v.end(),cmp);    //with built-in O(nlogn)
    /*int len = v.size();
    for(int i=0;i<len;i++)          //without built-in O(nlogn)
    {
        for(int j=0;j<i;j++)
            if(cmp(v[i],v[j]))
                swap(v[i],v[j]);
    }*/
    for(auto x:v)
        cout << x << " ";
    return 0;
}
