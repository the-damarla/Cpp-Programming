#include <bits/stdc++.h>

using namespace std;

/*TestCases : [2,5,6,-6,16,2,3,6,5,3]

               As sum of the array is : 42 and it's double is 84
               Now the multiplication of one of the pair is ---> 16 * 6 = 96
               So we found a pair greater than double the sum of the array so TRUE

               [2,2,2,2,4,1]    ---> sum : 13   and it's double ---> 26
                                    As we cannot find a pair whose multiplication is greater than 26
                                    So FALSE
*/

string Check(vector<int> v, int n)
{
    int s = 0;
    for(auto x:v)
        s+=x;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((v[i] * v[j]) > (2 * s))
            {
                return "True";
            }
        }
    }
    return "false";
}

int main()
{
    cout << "Enter \'0\' to stop giving input" << endl;
    vector<int> v;
    while(1)
    {
        int x;cout << "Enter data : ";cin >> x;
        if(x  == 0)break;
        else v.push_back(x);
    }
    cout << Check(v,v.size());
    return 0;
}
