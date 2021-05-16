#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    int v;
    vector <int> *adj;
public:
    Graph(int v);
    void addEdge(int v, int u);
    bool DFS(int s);
    bool DFSC(int s,bool visited[], int parent);
    void print();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new vector <int>[v];
}

void Graph::addEdge(int v, int u)
{
    adj[v].push_back(u);
}

bool Graph::DFSC(int s, bool visited[], int parent)
{
    visited[s] = true;
    //cout << s << " ";
    for(auto v:adj[s])
    {
        if(visited[v] == false)
        {
            if(DFSC(v,visited,s) == true)
                return true;
        }
        else if(v != parent)
            return true;
    }
    return false;
}

bool Graph::DFS(int s)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i] = false;
    for(int i=0;i<v;i++)
    {
        if(visited[i] == false)
        {
            if(DFSC(i,visited,-1) == true)
                return true;
        }
    }
    return false;
}

void Graph::print()
{
    cout << "\n\n";
    for(int i=0;i<v;i++)
    {
        cout << "Connected vertices to " << i << " are :";
        for(auto z:adj[i])
        {
            cout << z << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int main()
{
    cout << "Enter Number of Vertex : ";
    int x;cin >> x;
    Graph g(x);
    for(int i=0;i<x;i++)
    {
        cout << "Enter a number greater than " << x << " to break the loop\n";
        for(int j=0;i<x;j++)
        {
            int y;cout << "Enter vertex connected to " << i << " :";cin >> y;
            if(y > x)
            {
                break;
            }
            else
            {
                g.addEdge(i,y);
            }
        }
    }
    bool y = g.DFS(0);
    g.print();
    if(y)
    {
        cout << "Cycle is present..!!!\n\n";
    }
    else
        cout << "Cycle is not present..!!\n\n";
    return 0;
}
