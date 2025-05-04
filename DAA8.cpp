#include <iostream>
using namespace std;
const int MAX = 100;
void dfs(int graph[MAX][MAX], int n, int current, int visited[MAX]) {
    cout << current << " ";
    visited[current] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[current][i] && !visited[i]) {
            dfs(graph, n, i, visited);
        }
    }
}
int main() {
    int graph[MAX][MAX], n, edges, u, v, start;
    cout << "Enter number of vertices: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter " << edges << " edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    cout << "Enter starting vertex for DFS: ";
    cin >> start;
    int visited[MAX] = {0};
    cout << "DFS Traversal starting from node " << start << ": ";
    dfs(graph, n, start, visited);
    cout << endl;
    return 0;
}

