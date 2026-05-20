#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        // Pick the unvisited vertex with smallest distance
        int u = -1, minDist = INT_MAX;
        for (int i = 0; i < V; i++)
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        if (u == -1) break;
        visited[u] = true;

        // Relax neighbors
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "  to " << i << " = ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
