#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector <int> v;
    while(1)
    {
        cout << "Enter input : ";int x;cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    cout << "\nEnter a value to remove : ";int x;cin >> x;
    //int len = v.size();
    for(int i=0;i<v.size();i++)
        if(x == v[i])
            v.erase(v.begin()+i);
    cout << "\nOutput is : ";
    for(auto x:v)
        cout << x << " ";
    return 0;
}
