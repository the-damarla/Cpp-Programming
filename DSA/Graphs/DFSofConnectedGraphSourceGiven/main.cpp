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
    void DFS(int s);
    void DFSC(int s,bool visited[]);
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

void Graph::DFSC(int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for(auto v:adj[s])
    {
        if(visited[v] == false)
        {
            DFSC(v,visited);
        }
    }
}

void Graph::DFS(int s)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i] = false;
    DFSC(s,visited);
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
    for(int i=0;i<x;i++)
    {
        cout << "DFS of Graph with source as " << i << " node is : ";
        g.DFS(i);
        cout << "\n";
    }
    return 0;
}
