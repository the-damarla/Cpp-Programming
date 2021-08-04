#include <bits/stdc++.h>

using namespace std;

void NumberOfDuplicates(vector<int> k)
{
    int len = k.size();
    set<int> s,dup;
    for(int i=0;i<len;i++)
    {
        if(s.find(k[i]) != s.end())
            dup.insert(k[i]);
        else
            s.insert(k[i]);
    }
    cout << "Number of Duplicates in given array are/is : " << dup.size();
}

void PreviousSmaller(vector<int> k)
{
    int len = k.size();
    cout << "Given Array : ";
    for(auto x: k)
        cout << x << " ";
    cout << "\nTheir Previous smaller are : ";
    stack<int> stck;
    for(int i=0;i<len;i++)
    {
        while(stck.empty() == false && stck.top() >= k[i])
            stck.pop();
        int cur = (stck.empty())?-1:stck.top();
        cout << cur << " ";
        stck.push(k[i]);
    }
}

void PreviousGreater(vector<int> k)
{
    int len = k.size();
    cout << "Given Array is : ";
    for(auto x:k)
        cout << x << " ";
    stack<int> stck;
    cout << "\nTheir Previous Greater elements : ";
    for(int i=0;i<len;i++)
    {
        while(stck.empty() == false && stck.top() <= k[i])
            stck.pop();
        int cur = stck.empty()?-1:stck.top();
        cout << cur << " ";
        stck.push(k[i]);
    }
}

void NextSmaller(vector<int> k)
{
    int len = k.size();
    vector<int> store;
    stack<int> stck;
    for(int i=len-1;i>=0;i--)
    {
        while(stck.empty() == false && stck.top() >= k[i])
            stck.pop();
        int cur = (stck.empty())?-1:stck.top();
        store.push_back(cur);
        stck.push(k[i]);
    }
    reverse(store.begin(),store.end());
    cout << "Given Array : ";
    for(auto x:k)
        cout << x << " ";
    cout << "\nTheir NextSmaller are : ";
    for(auto x:store)
        cout << x << " ";
}

void NextGreater(vector<int> k)
{
    int len = k.size();
    vector<int> store;
    stack<int> stck;
    for(int i=len-1;i>=0;i--)
    {
        while(stck.empty() == false && stck.top() <= k[i])
            stck.pop();
        int cur = (stck.empty())?-1:stck.top();
        store.push_back(cur);
        stck.push(k[i]);
    }
    reverse(store.begin(),store.end());
    cout << "Given array is : ";
    for(auto x:k)
        cout << x << " ";
    cout << "\nTheir next greater elements are : ";
    for(auto x: store)
        cout << x << " ";
}

void leaders(vector<int> k)
{
    int len = k.size();
    int cur = k[len-1];
    vector<int> store;
    store.push_back(cur);
    for(int i=len-2;i>=0;i--)
    {
        if(cur < k[i])
        {
            cur = k[i];
            store.push_back(cur);
        }
    }
    reverse(store.begin(),store.end());
    cout << "Leaders of the given array are : ";
    for(auto x: store)
        cout << x << " ";
}

void profit(vector<int> prices)
{
    int len = prices.size();
    int prof = 0;
    for(int i=1;i<len;i++)
    {
        if(prices[i-1] < prices[i])
        {
            prof += (prices[i] - prices[i-1]);
        }
    }
    cout << "Profit is : " << prof;
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> k;
    while(1)
    {
        int x;cout << "Enter prices : ";cin >> x;
        if(x != 0)k.push_back(x);
        else break;
    }
    cout << "\n\n";
    profit(k);
    cout << "\n\n";
    leaders(k);
    cout << "\n\n";
    NextGreater(k);
    cout << "\n\n";
    PreviousSmaller(k);
    cout << "\n\n";
    NextSmaller(k);
    cout << "\n\n";
    PreviousGreater(k);
    cout << "\n\n";
    NumberOfDuplicates(k);
    cout << "\n\n";
    return 0;
}
