#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void nextPermutation(vector<int> v)
{
    cout << "Enter permutations to be done : ";int x;cin >> x;
    for(int i=0;i<x;i++)
    {
        if(next_permutation(v.begin(),v.end()))
            for(auto c:v)
                cout << c << " ";
        cout << "\n";
        /*if(prev_permutation(v.begin(),v.end()))
            for(auto c:v)
                cout << c << " ";*/
    }
}

int main()
{
    cout << "Enter \'0\' to stop giving input : " << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter an element : ";cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    nextPermutation(v);
    return 0;
}
