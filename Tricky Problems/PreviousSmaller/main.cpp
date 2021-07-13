#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void prevSmall(vector<int> v)
{
    int len = v.size();
    stack<int> stck;
    for(int i=0;i<len;i++)
    {
        while(stck.empty() == false && stck.top() >= v[i])
            stck.pop();
        int k = stck.empty() ? -1 : stck.top();
        cout << k << " ";
        stck.push(v[i]);
    }
}

int main()
{
    cout << "Enter \"0\" To stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 0)
        {
            break;
        }
        else
            v.push_back(x);
    }
    prevSmall(v);
    return 0;
}
