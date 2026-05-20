#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge { int u, v, w; };

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter each edge as: source destination weight\n";

    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    int src;

    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    for (auto &e : edges)
    {
        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.w < dist[e.v])
        {
            cout << "Graph contains a negative-weight cycle!\n";
            return 0;
        }
    }

    cout << "\nShortest distances from vertex " << src << ":\n";
    
    for (int i = 0; i < V; i++)
    {
        cout << "  to " << i << " = ";
    
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    
    return 0;
}
