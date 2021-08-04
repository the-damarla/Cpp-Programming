#include <bits/stdc++.h>

using namespace std;

void GetAnalogous(vector<int> CD,int n,int lb,int ub)
{
    vector<int> A(n+1,0);
    A[0] = lb;
    for(int i=0;i<n;i++)
    {
        A[i+1] = (A[i] - CD[i]);
    }
    int maxi = *max_element(A.begin(),A.end());
    int mini = *min_element(A.begin(),A.end());
    if(maxi > ub || mini < lb || mini > ub || maxi < lb)
    {
        cout << "not Possible Gone";
        return;
    }
    cout << "Possible Analogous Arrays are : " << ub - maxi + 1;
    return;
}

int main()
{
    cout << "Enter \'0\' to stop giving" << endl;
    vector<int> CD;
    while(1)
    {
        int x;cout << "enter data : ";cin >> x;
        if(x == 0)break;
        CD.push_back(x);
    }
    int lb;cout << "Enter lower bound : ";cin >> lb;
    int ub;cout << "Enter upper bound : ";cin >> ub;
    GetAnalogous(CD,CD.size(),lb,ub);
    return 0;
}
