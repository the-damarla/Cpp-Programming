#include <iostream>
#include <vector>

using namespace std;

void segregate(vector<int> &v)
{
    int len = v.size();
    int high = len-1;
    int low = 0;
    int i = 0;
    while(i <= high)
    {
        if(v[i] == 0)
        {
            swap(v[low++],v[i++]);
        }
        else if(v[i] == 1)
        {
            i++;
        }
        else
        {
            swap(v[i],v [high--]);
        }
    }
}

void print(vector<int> v)
{
    int len = v.size();
    for(int i=0;i<len;i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    cout << "Enter \"-1\" to stop giving input and input must be 0,1,2" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter an element : ";int x;cin >> x;
        if(x == -1)
            break;
        else
            v.push_back(x);
    }
    cout << "Given vector : ";
    print(v);
    segregate(v);
    cout << "\nAfter Segregation : ";
    print(v);
    return 0;
}
