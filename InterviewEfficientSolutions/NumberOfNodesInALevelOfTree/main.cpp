#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
public:
    Graph(int v);
    void AddEdge(int v,int u);
    void BFS(int s,int l);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
};

void Graph::AddEdge(int v,int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
};

void Graph::BFS(int s,int l)
{
    vector<bool> visited(V,false);
    vector<int> level(V,0);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    while(!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop();
        for(auto i=adj[s].begin();i != adj[s].end();i++)
        {
            if(!visited[*i])
            {
                level[*i] = level[s] + 1;
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
    int c = 0;
    for(int i=0;i<V;i++)
    {
        if(level[i] == l)c++;
    }
    cout << "\nNumber of nodes in level " << l << " are : " << c;
}

int main()
{
    cout << "*      NODES STARTS FROM \"0\"        *" << endl;
    cout << "Enter number of edges : ";int n;cin >> n;
    Graph g(n+1);
    for(int i=0;i<n-1;i++)
    {
        cout << "Enter 1st edge : ";int v;cin >> v;
        cout << "Enter 2nd edge : ";int u;cin >> u;
        g.AddEdge(v,u);
    }
    cout << "Enter level  : ";int l;cin >> l;
    cout << "BFS of given tree : ";g.BFS(0,l);
    return 0;
}
