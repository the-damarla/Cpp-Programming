#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> nums, int target)
{
    int c = 0;
    for(auto x:nums)
    {
        if(x < target)
        {
            c++;
        }
        else if(x == target)
        {
            c++;
            return c-1;
        }
        else if(x > target)
            return c;
    }
    return c;
}

int main()
{
    cout << "Enter \"0\" to Stop giving input " << endl;
    vector <int> v;
    while(1)
    {
        cout << "Enter an element : ";int x;cin >> x;
        if(x == 0)
            break;
        else
            v.push_back(x);
    }
    int x;cout << "Enter an Element to search its insert position : ";cin >> x;
    int y = searchInsert(v,x);
    cout << "Element insert position is : " << y ;
    return 0;
}
