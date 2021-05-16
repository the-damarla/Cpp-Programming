#include <iostream>
#include <vector>

using namespace std;

void addedge(vector <int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector <int> adj[], int v)
{
    for(int i=0;i<v;i++)
    {
        for(auto x:adj[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cout << "Hello world!" << endl;
    int v = 4;
    vector <int> adj[v];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    print(adj,v);
    return 0;
}
