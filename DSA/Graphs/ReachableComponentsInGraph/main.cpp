#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int v;
    vector <int> *adj;
public:
    Graph(int v);
    void addedge(int u, int v);
    void BFS(int s,bool visited[]);
    void BFSD();
    void print();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new vector<int> [v];
}

void Graph::addedge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::BFS(int s, bool visited[])
{
    /*bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i] = false;*/
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(q.empty() == false)
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n\n";
}

void Graph::BFSD()
{
    int count = 0;
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i] = false;
    for(int i=0;i<v;i++)
    {
        if(visited[i] == false)
        {
            BFS(i,visited);
            count++;
        }
    }
    cout << "\nThe Number of Connected subgraphs are/is :"<< count << "\n\n";
}

void Graph::print()
{
    cout << "\n\n";
    for(int i=0;i<v;i++)
    {
        cout << "Connected edges from "<< i << " :";
        for(auto z:adj[i])
            cout << z << " ";
        cout << "\n";
    }
}

int main()
{
    cout << "Enter number of vertices : ";int x;cin >> x;
    Graph g(x);
    for(int i=0;i<x;i++)
    {
        cout << "Enter a number greater that " << x << " to break the loop\n";
        for(int j=0;j<x;j++)
        {
            cout << "entr vetex connected to " << i << " : ";int y;cin >> y;
            if(y > x)
            {
                break;
            }
            else
            {
                g.addedge(i,y);
            }
        }
        //g.BFS(i);
    }
    cout << "\n\n";
    //g.BFS(0);
    g.BFSD();
    g.print();
    return 0;
}
