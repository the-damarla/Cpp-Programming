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
    void addEdge(int v, int u);
    void out();
    void in(int s);
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

void Graph::out()
{
    for(int i=0;i<v;i++)
    {
        int c = 0;
        for(auto v:adj[i])
            c++;
        cout << "Out Degree of " << i << " is :" << c << "\n";
    }
}

void Graph::in(int s)
{
    int c = 0;
    for(int i=0;i<v;i++)
    {
        for(auto v :adj[i])
        {
            if(v == s)
                c++;
        }
    }
    cout << "InDegree of " << s << " is : " << c << "\n" ;
}

int main()
{
    cout << "Enter number of vertex : ";int x;cin >> x;
    Graph g(x);
    for(int i=0;i<x;i++)
    {
        cout << "Enter a number greater than " << x << " to break the loop\n";
        for(int j=0;j<x;j++)
        {
            int y;cout << "Enter vertex of " << i << " :";cin >> y;
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
    g.out();
    cout << "\n";
    for(int i=0;i<x;i++)
        g.in(i);
    return 0;
}
