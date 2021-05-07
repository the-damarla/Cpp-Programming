#include <iostream>

using namespace std;

int* sort(int *p,int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            if(*(p+i) > *(p+j))
            {
                swap(*(p+i),*(p+j));
            }
        }
    }
    return p;
}

int lexi(string s)
{
    int c=0,len = s.size();
    int *p = new int[len];
    for(int i=0;i<len;i++)
    {
        if(int(s[i]) > 96 && int(s[i]) < 123)
        {
            *(p+c) = s[i];
            c++;
        }
    }
    p = sort(p,c);
    for(int i=0;i<c;i++)
    {
        cout << char(*(p+i)) << " ";
    }
    return 0;
}

int main()
{
    string s; cout << "Enter the string : "; getline(cin, s);
    lexi(s);
    return 0;
}
