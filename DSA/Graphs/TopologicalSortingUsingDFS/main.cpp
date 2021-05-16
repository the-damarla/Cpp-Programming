#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
    int v;
    vector <int> *adj;
public:
    Graph(int v);
    void addEdge(int v, int u);
    bool DFS();
    bool DFSD(int s, bool visited[], bool recSt[]);
    void topologicalsort();
    void topo(int s, bool visited[], stack<int> &Stack);
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new vector<int>[v];
}

void Graph::addEdge(int v, int u)
{
    adj[v].push_back(u);
}

void Graph::topo(int s, bool visited[], stack<int> &Stack)
{
    visited[s] = true;
    for(auto v:adj[s])
    {
        if(!visited[v])
        {
            topo(v,visited,Stack);
        }
    }
    Stack.push(s);
}

void Graph::topologicalsort()
{
    stack <int> Stack;
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i] = false;
    for(int i=0;i<v;i++)
    {
        if(visited[i] == false)
        {
            topo(i,visited,Stack);
        }
    }
    while(Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

bool Graph::DFSD(int s, bool visited[],bool recSt[])
{
    visited[s] = true;
    recSt[s] = true;
    for(auto v:adj[s])
    {
        if(visited[v] == false && DFSD(v,visited,recSt))
            return true;
        else if(recSt[v] == true)
            return true;
    }
    recSt[s] = false;
    return false;
}

bool Graph::DFS()
{
    bool visited[v+1],recSt[v+1];
    for(int i=0;i<v;i++)
    {
        visited[i] = recSt[i] = false;
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i] == false)
        {
            if(DFSD(i,visited,recSt) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cout << "Enter Number of Vertex : " << endl;
    int x;cin >> x;
    Graph g(x);
    for(int i=0;i<x;i++)
    {
        cout << "enter a number greater than " << x << " to break the loop\n";
        for(int j=0;j<x;j++)
        {
            int y;cout << "enter vertex connected to " << i << " :";cin >> y;
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
    if(g.DFS())
    {
        cout << "Topological Sort is Not Possible in DIRECTED CYCLIC GRAPH\n";
    }
    else
    {
        g.topologicalsort();
    }
    return 0;
}
