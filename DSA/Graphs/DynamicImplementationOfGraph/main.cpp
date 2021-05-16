#include <iostream>
#include <vector>

using namespace std;

void addedge(vector<int> adj[],int v,int u)
{
    adj[v].push_back(u);
    //adj[u].push_back(v);
}

void print(vector <int> adj[], int len)
{
    cout << "\n\n";
    for(int i=0;i<len;i++)
    {
        cout << "connected vertices to vertex " << i << " -> ";
        for(auto z:adj[i])
        {
            cout << z << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cout << "Enter number of vertex : ";
    int x;cin >> x;
    vector <int> adj[x];
    for(int i=0;i<x;i++)
    {
        cout << "Enter a number greater than " << x << " to break the loop ;\n";
        for(int j=0;i<x;j++)
        {
            cout << "enter connected vertex of " << i << "  : ";
            int y;cin >> y;
            if(y > x)
            {
                break;
            }
            else
                addedge(adj,i,y);
        }
    }
    print(adj,x);
    return 0;
}
