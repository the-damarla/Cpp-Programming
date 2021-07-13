#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void PreviousGreat(vector<int> v)
{
    stack<int> mystack;
    //mystack.push(0);
    int len = v.size();
    for(int i=0;i<len;i++)
    {
        if(mystack.empty())
        {
            cout << "-1" << " ";
            mystack.push(v[i]);
        }
        else
        {
            while(mystack.empty() == false && mystack.top() <= v[i])
                mystack.pop();
            int k = (mystack.empty()) ? -1 : mystack.top();
            cout << k << " ";
            mystack.push(v[i]);
        }
    }
}

int main()
{
    cout << "Enter \"0\" to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter an element : ";int x;cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    PreviousGreat(v);
    return 0;
}
