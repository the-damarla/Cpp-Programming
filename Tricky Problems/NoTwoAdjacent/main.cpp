#include <iostream>

using namespace std;

void adjacent()
{
    string s;cout << "Enter a string : ";cin >> s;
    int c = 0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i] == s[i-1])
        {
            c++;i++;
        }
    }
    cout << "Number of elements to remove : " << c << "\n";
}

int main()
{
    cout << "Hello world!" << endl;
    cout << "Enter Number of test cases : ";int x;cin >> x;
    for(int i=0;i<x;i++)
    {
        adjacent();
    }
    return 0;
}
