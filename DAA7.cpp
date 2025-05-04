#include <iostream>
using namespace std;
const int MAX = 100;
void bfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    cout << "BFS Traversal starting from node " << start << ": ";
    while (front < rear) {
        int current = queue[front++];
        cout << current << " ";
        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    cout << endl;
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
    cout << "Enter starting vertex for BFS: ";
    cin >> start;
    bfs(graph, n, start);
    return 0;
}

