#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v;
    cout << "\n\nEnter \"0\" to stop giving inputs\n\n";
    while(1)
    {
        cout << "enter elements of array : ";
        int x; cin >> x;
        if(x == 0)
        {
            break;
        }
        else
            v.push_back(x);
    }
    for(auto x: v)
    {
        cout << x << " ";
    }
    return 0;
}
