#include <iostream>
#include <vector>

using namespace std;

void segregate(vector<int> &v)
{
    int len = v.size();
    int c = 0;
    for(int i=0;i<len;i++)
    {
        if(v[i] > 0)             //-ve elements will come to the right end if we keep '>' the order of +ve will not be changed
        {                        //-ve element will come to the left end if we keep '<' the order of -ve will not be changed
            swap(v[i],v[c]);
            c++;
        }
    }
}

void print(vector<int> v)
{
    int len = v.size();
    for(int i=0;i<len;i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    cout << "Enter \"20\" to stop giving input;" << endl;
    vector<int> v;
    while(1)
    {
        cout << "Enter an element : ";int x;cin >> x;
        if(x == 20)
            break;
        else
            v.push_back(x);
    }
    cout << "List before Segregation : ";
    print(v);
    segregate(v);
    cout << "\nList after segregation : ";
    print(v);
    return 0;
}
