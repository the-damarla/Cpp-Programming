#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void checkDuplicates(vector<string> v, int n)
{
    sort(v.begin(),v.end());
    int c = 0;
    for(int i=1;i<n;i++)
    {
        if(v[i] != v[i-1])
            c++;
    }
    if(c == 0 && n > 1)
        c = 1;
    cout << "Number of duplicate elements : " << c ;
}

void checkDuplicates(vector<string> v)
{
    set<string> s,dup;
    //vector<string> uni;
    //auto uni = unique(v.begin(),v.end());
    int len = v.size();
    //s.insert(v[0]);
    for(int i=0;i<len;i++)
    {
        if(s.find(v[i]) != s.end())
        {
            dup.insert(v[i]);
        }
        else
            s.insert(v[i]);
    }
    cout << "Number of duplicate elements are : " << dup.size() << "\n";
    cout << "Given elements : ";
    for(auto x: v)
        cout << x << " ";
    cout << "\nSet Elements : ";
    for(auto x: s)
        cout << x << " ";
    cout << "\nDup Elements are : ";
    for(auto x:dup)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    cout << "Enter \'1\' to stop giving inputs" << endl;
    vector<string> v;
    while(1)
    {
        string s;cout << "Enter a string : ";cin >> s;
        if(s[0] == '1')
            break;
        else
            v.push_back(s);
    }
    checkDuplicates(v);
    checkDuplicates(v,v.size());
    return 0;
}
