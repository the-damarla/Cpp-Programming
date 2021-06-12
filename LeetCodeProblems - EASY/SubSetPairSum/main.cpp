#include <iostream>
#include <vector>

using namespace std;

int countpairsum(vector <int> v,int n, int sum)
{
    if(n == 0)
    {
        return (sum == 0)?1:0;
    }
    return countpairsum(v,n-1,sum) + countpairsum(v,n-1,sum-v[n-1]);
}

int main()
{
    cout << "Enter \"0\" to stop the loop" << endl;
    vector <int> v;
    while(1)
    {
        int y;cout << "enter input : ";cin >> y;
        if(y == 0)
            break;
        else
            v.push_back(y);
    }
    cout << "Enter sum u want : " ;int sum;cin >> sum;
    int n = v.size();
    int x = countpairsum(v,n,sum);
    cout << "\nNo. of subsets that have their sum as " << sum << " is/are : " << x ;
    return 0;
}
