#include <bits/stdc++.h>

using namespace std;

/*You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

void maxProfit(vector<int>& v)
{
        int len = v.size();
        int profit = 0;
        int mini = v[0];
        for(int i=0;i<len;i++)
        {
            mini = min(mini,v[i]);
            if(mini < v[i])
                profit = max(profit,v[i]-mini);
        }
        cout <<"Max Profit is : " << profit;
}

/*Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).*/

void BuyStock(vector<int> v,int n)                  //Of Complexity O(n) & Simple one
{
    int profit = 0;
    for(int i=1;i<n;i++)
    {
        if(v[i] > v[i-1])
            profit += (v[i] - v[i-1]);
    }
    cout <<"\nMax profit we can make is : " << profit;
}

int BuyStock(vector<int> v,int start, int last)          //Naive & Recursive of Time Complexity O(N^2)
{
    if(last <= start)
    {
        return 0;
    }
    int profit = 0;
    for(int i=start;i<last;i++)
    {
        for(int j=i+1;j<=last;j++)
        {
            int curprofit = (v[j] - v[i]) + BuyStock(v,start,i-1) + BuyStock(v,j+1,last);
            profit = max(profit,curprofit);
        }
    }
    return profit;
}

int main()
{
    cout << "Enter \"-1\" to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter an element : ";int x;cin >> x;
        if(x == -1)
            break;
        else
            v.push_back(x);
    }
    int maxprofit = BuyStock(v,0,v.size()-1);
    cout << "Max profit we can gain is : " << maxprofit;
    BuyStock(v,v.size());
    maxProfit(v);
    return 0;
}
