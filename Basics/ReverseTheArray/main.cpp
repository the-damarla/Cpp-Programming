#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int> &v)
{
    int i = v.size()-1;
    int j = 0;
    while(j < i)
    {
        swap(v[j],v[i]);
        i--;j++;
    }
}

int main()
{
    cout << "Enter \"0\" To stop giving input : " << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    cout << "Before reversing the array : ";
    for(auto x: v)
        cout << x << " ";
    cout << "\n";
    reverseArray(v);
    cout << "After reversing the array : ";
    for(auto x: v)
        cout << x << " ";
    return 0;
}
