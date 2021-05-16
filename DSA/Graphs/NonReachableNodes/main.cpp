#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int v;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    vector<int> *adj;
public:
    Graph(int v);  // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void BFS(int s);

    void print();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new vector<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

/*void addedge(vector <int> adj[], int v, int u)
{
    adj[v].push_back(u);
}*/

void Graph::BFS(int s)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v: adj[u])
        {
            if(visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
    int coun = 0;
    cout << "\nThe non-reachable nodes from " << s << " is/are : ";
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
		    coun++;
            cout << i << " ";
		}
	}
	cout << "\nThe count : " << coun << "\n";
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
}

int main()
{
    cout << "Hello world!" << endl;
    cout <<"enter number of vertices : ";int x;cin >> x;
    Graph g(x);
    for(int i=0;i<x;i++)
    {
        cout << "enter a number greater than " << x << " to break the loop  \n";
        for(int j=0;j<x;j++)
        {
            cout << "enter connected vertex to " << i << " : ";
            int y;cin >> y;
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
        g.BFS(i);
    }
    g.print();
    return 0;
}
